// Fill out your copyright notice in the Description page of Project Settings.


#include "R1PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "kismet/KismetMathLibrary.h"

AR1PlayerController::AR1PlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	// Super는 AR1PlayerController를 상속하고 있는 부모클래스를 가리킨다.
	// Super(ObjectInitializer)는 부모 클래스의 생성자를 호출하는 역할을 한다.
{

}
// 추가로 까먹으면 안되는 한가지는 에셋같은 거를 연동하는 부분을 우리가 생성자에서 긁어오게끔 하지 않았다.
// 여기다가 ConstructorHelpers시리즈를 이용해가지고 하드코딩해도 됐겠지만 
// 그러면 너무 하드코딩이고 경로 바뀌면 또 깨지고 막 이런 문제가 있기 때문에 그걸 우리가 블루프린트에서 설정하게끔 우리가 열어놨다.

void AR1PlayerController::BeginPlay()
{
	Super::BeginPlay();
	// 그리고 어지간한 가상함수들은 이렇게 다 무조건 자기 직속 부모꺼를 다시 호출해줘야 한다.
	// 빼먹으면 진짜 찾기 힘든 버그들이 일어난다.

	//auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		// 이것은 대입을 하자마자 널체크하는 방법이다.
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
		// 두번째 인자는 우선순위를 의미한다. 0이 가장 높은 우선순위이다.
	}
}

void AR1PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(TestAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Test);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Turn);
	}
	// SetupInputComponent 함수가 실행될때 Input_Test함수를 실행해라. 콜백함수방식이다.
}

void AR1PlayerController::Input_Test(const FInputActionValue& InputValue)
{
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Cyan, TEXT("Input_Test"));
}

void AR1PlayerController::Input_Move(const FInputActionValue& InputValue)
{
	FVector2D MovementVector = InputValue.Get<FVector2D>();

	if (MovementVector.X != 0)
	{
		/*FVector Direction = FVector::ForwardVector * MovementVector.X;
		GetPawn()->AddActorWorldOffset(Direction * 30.f);*/
		// ForwardVector는 그냥 (1,0,0)이라는 Vector이다.

		FRotator Rotator = GetControlRotation();
		// 내가 바라보는 방향을 기준으로, 어떤 회전값을 기준으로 ForwardVector를 가져온다.
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.X); // (worlddir, Scaleval)
		// Add Movement Input 함수는 현재 캐릭터가 나아가는 방향 벡터를 받고 추가로 스케일만 더 받으면 알아서 계산해주어 위치를 세팅해주게 된다. 
		// 입력값을 매핑할 때 지정해주었던 스케일을 곧바로 반환받아 해당 함수에 넣어주면 따로 계산 없이 이동 이벤트를 만들 수 있다.
		// 내부적으로 델타타임 곱해가지고 시간 곱하고 스피드에다가 쿠션 곱해서 하는 거는 당연히 무브먼 컴포넌트에서 알아서 해준다.
		// 즉, 기능을 만들어 준 것을 consume을 하는 기능을 하는 것은 movementcomponent가 해준다.
		// 결과적으로 우리가 add movement input에다가 꽂아주는 
		// 이 벡터는 scale value랑 곱해져 가지고 내가 이동하고 싶은 방향에 대한 의사표시를 해주는 것
		// MoveInput은 폰에다가 추가
	}

	if (MovementVector.Y != 0)
	{
		/*FVector Direction = FVector::RightVector * MovementVector.Y;
		GetPawn()->AddActorWorldOffset(Direction * 30.f);*/

		// GetControlRotation을 해서 그걸 기준으로 Forward를 했다
		// 즉 플레이어 컨트롤러의 회전값을 가져와서 그것을 기준으로해서 방향대로 Move를 했다.
		FRotator Rotator = GetControlRotation();
		// 내가 바라보는 방향을 기준으로, 어떤 회전값을 기준으로 ForwardVector를 가져온다.
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.Y); //(worlddir, Scaleval)
	}
}

void AR1PlayerController::Input_Turn(const FInputActionValue& InputValue)
{
	float TurnValue = InputValue.Get<float>();
	AddYawInput(TurnValue); // 회전과 관련된 인풋은 플레이어 컨트롤러에다가 넣어준다
	// ControlRotation은 플레이어 컨트롤러에다가 사실상 회전값을 기입을 하는거에 불과하다.
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Pawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AR1Pawn::AR1Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComponent->InitCapsuleSize(34.0f, 88.0f);
	RootComponent = CapsuleComponent;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	Mesh->SetupAttachment(CapsuleComponent);
	Mesh->SetRelativeLocationAndRotation(FVector(0, 0, -88), FRotator(0, -90, 0));
	// 참고로 회전은 pitch yaw roll 순이고, y, z, x 순서이다.

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(CapsuleComponent);	
	SpringArm->TargetArmLength = 700.0f;
	SpringArm->SetRelativeRotation(FRotator(-30, 0, 0));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AR1Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AR1Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AR1Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
// Pawn은 Actor이긴한데, 빙의를 해서 컨트롤러의 의해서 입력을 받을수 있다.
// 입력을 받아가지고 그 부분을 처리하는 것은 여기 pawn의 스크립트안에서 SetupPlayerInputComponent라는 함수에서 처리해줘도 된다
// 하지만 좀더 깔끔한 방법은 플레이어 컨트롤러에 옮기는게 더 깔끔하다.
// 그래서 두가지 방식이 다 가능하긴한데, 프로젝트가 커지거나 하면 권장되는 방식는
// 키보드 입력, 맵핑 등 관련된 부분들은 다 플레이어 컨트롤에다가 넣어주는게 권장됨.

// 빙의를 하는 방법은 두가지 방법이 있다.
// 뷰포트에 pawn을 배치하고 possess를 하는 방법과 
// 게임모드에 Default pawn Class를 설정하고 Playerstart의 위치에서 시작을 하는 두가지 방식이 있다.

// 플레이어 컨트롤러는 어떤 액터인데 사용자가 사용하는 폰을 컨트롤하는 용도로 사용이 된다. 

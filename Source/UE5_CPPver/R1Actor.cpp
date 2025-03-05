// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1Object.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AR1Actor::AR1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// UStaticMeshComponent타입으로 Box라는 이름의 오브젝트를 만들어준다
	// 이러면 에디터 상에서 StaticMesh로 Box라는 오브젝트가 액터 산하에 만들어진다.
	//Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));

	// 에셋을 C++에서 연결해주는 방법, 보통 에셋같은 경우는 블루 프린트에서 연결해주는게 일반적이다.
	//ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/_Art/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
	// ConstructorHelpers::FObjectFinder는 CDO를 찾는 역할, 즉, 우리가 찾고싶은 타입의 객체를 찾아오는 역할
	// 그래서 UStaticMesh타입을 넣어줬다
	// TEXT안에는 우리가 스태틱 메시를 넣어주고싶으니까 스태틱메시가 있는 경로를 넣어줘야한다.
	// 에디터에서 컨텐츠 브라우저에서 에셋을 ctrl + c하면 경로를 가져올수 있다.
	// 추가로 ConstructorHelpers::FClassFinder<> 라고 있다. 이 두가지를 많이 사용한다.
	// ConstructorHelpers::FClassFinder<>는 UCLASS를 찾는 역할.
	
	// 매시를 찾았으면 Box에 찾은 메시오브젝트를 적용해달라.
	/*if (FindMesh.Succeeded())
	{
		Box->SetStaticMesh(FindMesh.Object);
	}*/
	// 근데 이렇게 코드를 작성하고 에디터를 켜보면 매시가 적용이 안되어있을수 있다.
	// 그러면 에디터를 껐다가 다시 켜보면 적용이 된다.
	// 그리고 매시쪽에 리버트 표시가 생길수 있는데 있다는 거는 얘가 기본 상태가 아니라고 인지를 하고 있는 것이다.
	// 근데 우리가 방금 C++에서 여기다가 이렇게 넣어 놨으면 얘가 사실상 CDO 즉 기본 객체가 이걸로 만들어지는 것이기 때문에 얘가 기본 상태여야 되거든요
	// 이것도 이슈가 있는거니까 껐다가 다시 켜보면 리버트 버튼이	사라진다.

	// 그리고 추가로 가장 효과적으로 버그가 없는 방법은 그냥 Visual Studio 상에서 키는 게 제일 확실하다.

	//------------------------------------------------------
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Body;
	Body->SetRelativeScale3D(FVector(2, 1, 0.25f));

	Wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wing"));
	Wing->SetupAttachment(Body);
	Wing->SetRelativeLocationAndRotation(FVector(0, 0, 0), FRotator(0, 0, 0));
	Wing->SetRelativeScale3D(FVector(0.25f, 5, 1));
	
	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Body);
	Head->SetRelativeLocationAndRotation(FVector(30, 0, 0), FRotator(0, 0, 0));
	Head->SetRelativeScale3D(FVector(0.125f, 0.25f, 1));

	Wing->SetRelativeLocation(FVector(0, 0, 0));
	Head->SetRelativeLocation(FVector(0, 0, 0));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/_Art/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
	if (FindMesh.Succeeded())
	{
		Body->SetStaticMesh(FindMesh.Object);
		Wing->SetStaticMesh(FindMesh.Object);
		Head->SetStaticMesh(FindMesh.Object);
	}
}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();
	// 언리얼에서 제공하는 메모리 방식으로 관리한다
	// 이러면 delete라는건 아예 안해도 된다.
	/*obj1 = NewObject<UR1Object>();
	obj2 = NewObject<UR1Object>();*/

	//GEngine->ForceGarbageCollection(true);
	// 이 코드는 Unreal Engine의 가비지 컬렉션(GC)을 강제로 실행하는 함수입니다.
	// 즉, 현재 필요하지 않은 객체들을 정리하여 메모리를 회수하는 역할을 합니다.
	// true : 풀 퍼지(Full Purge) 모드로 실행 → 더 강력한 가비지 컬렉션 수행
	// false : 일반적인 가비지 컬렉션 수행

	// true와 false 차이
	// true (Full Purge 모드)
	// - 사용되지 않는 모든 객체를 즉시 제거
	// - 더 많은 메모리를 회수할 수 있음
	// - 하지만 GC에 시간이 오래 걸릴 수 있음(성능 부담)

	// false (일반 GC)
	// - 일반적인 가비지 컬렉션 실행
	// - 엔진이 자동으로 필요하다고 판단하는 객체만 정리
	// - 성능 부담이 적음

	// 사용시 주의사항
	// 프레임 드랍 가능성 🚨
	// - 가비지 컬렉션은 CPU 자원을 많이 사용하므로, 실시간 게임 플레이 도중 호출하면 프레임 드랍이 발생할 수 있음.
	// - 일반적으로 레벨 변경 직후 또는 로딩 화면에서 실행하는 것이 좋음.
	// 불필요한 호출 지양
	// - Unreal Engine은 자동으로 적절한 타이밍에 GC를 수행함.
	// - 너무 자주 호출하면 불필요한 성능 저하가 발생할 수 있음.

	// R1Actor가 자기의 타겟을 찾게끔 현재 맵에 있는 특정 액터를 찾고 싶은 기능은 UGameplayStatics 클래스에 많이 있다.
	//Target = UGameplayStatics::GetActorOfClass(GetWorld(), AR1Actor::StaticClass());
	// GetActorOfClass : 특정 클래스에 있는 하나의 액터 혹은 모든 액터를 다 갖고 오겠다

	// std::vector
	
	TArray<AActor*> Actors;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("heejune"), Actors);

	// 사실 STL에서 empty는 사실상 사이즈가 현재 0이냐 라는 개념인데 언리얼에서는 clear와 같은 기능이다.
	if (Actors.Num() > 0)
	{
		// Actors라는 배열의 크기가 0보다 크면 타겟에 Actors의 0번째 인덱스의 데이터를 넣어준다.
		Target = Actors[0];
	}
}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (obj1 == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Obj1 Deleted"));
	}
	if (obj2 == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Obj2 Deleted"));
	}*/
	// 이 상태에서 디버깅 시작을 누르고 breakpoint를 걸어서 확인해 보면
	// obj1는 hp,mp,speed와같은 정보는 안날라갔는데, name이 정상적으로 안뜨고
	// obj2는 정보도 다 뜨고 이름도 정상적으로 뜨고있다.
	// 즉, obj2가 유효한 이유는 UPROPERTY()를 넣어놨기 때문에 관찰대상으로서 관찰이 잘되고 있고
	// obj1은 잘못된것이다.
	// 언리얼에서 사용하는 요런 메모리 관리를 사용하실 거면 이 new property가 붙는
	// 혹은 이 garbage collection에 의해 가지고 회수가 되고 안 되고의 그 차이가 어떻게 구별이 되는지를 이해해야 된다고 보시면 돼요.
	// 하지만 어떤 케이스라고 하더라도 null 포인터가 되어가지고 안으로 들어가진 않아요 
	// 왜냐면 어차피 얘는 어찌됐건 오브젝트 자체가 포인터니까 메모리를 가리키고 있는 거니까 얘가 당장 0으로 밀리는 건 아니잖아요
	// 그러니까 얘가 null로는 들어가지 않는다는 것도 겸사겸사 확인할 수가 있네요, 그래서 더 무서운 것이다.

	// 즉, 가장 기본적으로 UClass, UProperty 혹은 나중에 가면은 UFunction 해가지고 어떤 함수에다가 얘는 관찰 대상이 되는 함수이다 라는 힌트도 붙일 수 있다. 
	// 일단 기본적인 아이를 내가 들고 있을거면 무조건 붙인다라고 생각하는것이 더 편리하다.

	// -------------------------
	// DeltaTime은 이전 프레임에서 현재 프레임까지의 시간을 나타낸다.

	if (Target != nullptr)
	{
		// 이동속도
		float Speed = 50.0f;
		// 이동거리
		float distance = DeltaTime * Speed;

		// 현재 위치를 가져온다
		FVector Location = GetActorLocation();

		FVector DirectionVector = Target->GetActorLocation() - GetActorLocation();
		DirectionVector.Normalize();

		// 새로운 위치를 설정해준다, 현재위치에 이동거리에 방향을 곱해준것을 더하면 새로운 위치가 나온다.
		// 참고로 ForwardVector는 X축 방향이다.
		/*FVector NewLocation = Location + DirectionVector * distance;
		SetActorLocation(NewLocation);*/
		// FVector::ForwardVector대신 normalized한 DirectionVector로 대체해도 된다.

		// 이 함수는 바뀐 방향벡터만 받아준다.
		// 현재 위치는 이 함수가 알아서 할테니 방향벡터만 알려줘라는 뜻.
		// 그래서 FVector::ForwardVector * distance를 넣어주면 된다.
		AddActorWorldOffset(DirectionVector * distance);

		// 참고로 World라는 말이 들어가 있거나 GetActorLocation 이렇게 좌표를 가져오는데 별다른 말이 없으면 월드 좌표를 기준.

		// 그래서 로컬 좌표계는 물체를 기준으로 하는 좌표계인거고 월드 좌표계는 항상 고정이고 어떤 방향을 바라보건 어떤 위치에 있건
		// 좌표계는 축이 고정이다

	}
	
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "MainActor.h"
#include "R1Actor.h"

// Sets default values
AMainActor::AMainActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// AR1Actor를 상속받은 블루 프린트 클래스를 가져오고 싶은거니까 가져온다. 
	// 그리고 가져오고 싶은 클래스가 블루프린트 클래스인 경우 BP_R1Actor_C 이렇게 갖고오고싶은 클래스끝에 _C를 붙여준다.
	ConstructorHelpers::FClassFinder<AR1Actor> FindClass(TEXT("/Script/Engine.Blueprint'/Game/BluePrints/BP_R1Actor.BP_R1Actor_C'"));

	// 찾았으면 ActorClass에 넣어준다.
	if (FindClass.Succeeded())
	{
		ActorClass = FindClass.Class;
	}
}

// Called when the game starts or when spawned
void AMainActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 위치와 로테이션을 잡아준다
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);

	// 잡아준 곳에 spawnactor
	//AR1Actor* Actor = GetWorld()->SpawnActor<AR1Actor>(Location,Rotation);
	//Actor = GetWorld()->SpawnActor<AR1Actor>(Location, Rotation);
	
	// c++에선 캐스팅이 대표적으로 4가지가 있다.
	// 1. static_cast
	// 2. dynamic_cast
	// 3. const_cast
	// 4. reinterpret_cast
	// 이 4개는 언리얼에서 사용하면 안되는건 아니다.
	// 하지만 dynamic_cast같은 경우 내가 만든 객체를 캐스팅함과 동시에 만약에 그 상속구조가 잘못되어가지고
	// 원래 상속을 하면 안되는 경우였다면 nullptr을 반환해준다.
	// 근데 언리얼에서 dynamic_cast랑 비슷한 cast가 있기 때문에 그걸 사용하는게 좋다.

	Actor = Cast<AR1Actor>(GetWorld()->SpawnActor(ActorClass));

	// 5초후 파괴
	Actor->SetLifeSpan(5.0f);
	
	//GetWorld()->DestroyActor(Actor);
}

// Called every frame
void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}


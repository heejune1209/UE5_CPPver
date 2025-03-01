// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"

// Sets default values
AR1Actor::AR1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();
	// 언리얼에서 제공하는 메모리 방식으로 관리한다
	// 이러면 delete라는건 아예 안해도 된다.
	/*obj1 = NewObject<UR1Object>();
	obj2 = NewObject<UR1Object>();*/

	GEngine->ForceGarbageCollection(true);
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
}



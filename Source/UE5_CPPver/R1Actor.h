// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R1Actor.generated.h"

class UR1Object;
class UStaticMeshComponent;

//벡터의 구성요소
//struct MyVector
//{
//	double x;
//	double y;
//	double z;
//
//	// 크기
//	// length,size
//	// sqrt(x*x, y*y, z*z);
//
//	// 방향
//	// 벡터의 자신의 벡터크기를 나눠주면된다.
//	// 이것은 크기가 1인 방향을 구하는것이기 때문에 Normalize 벡터(정규화된 벡터)를 구하는 것이다.
//	// (X / sqrt(Length), y / sqrt(Length), z / sqrt(Length))
//};
// 벡터는 크기와 방향을 동시에 가지고있다. 
// 그리고 크기가 1인 벡터를 단위벡터라고 한다.

UCLASS()
class UE5_CPPVER_API AR1Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AR1Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	// TObjectPtr은 언리얼에서 제공하는 포인터, 생 포인터를 사용하지말고 이 버전을 좀더 권장함.
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Wing;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Head;

	UPROPERTY(EditAnywhere, Category = Battle)
	TObjectPtr<class AActor> Target;

	/*UR1Object* obj1;
	UPROPERTY()
	UR1Object* obj2;*/
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	// BlueprintReadWrite는 블루프린트 코드에서 getSet 같은 걸 할 수 있느냐이다.
	// Category = Stat은 category를 Stat으로 하겠다이다. 이렇게 하고 에디터상에서 보면 details에서 
	// Category밑에 Stat이라고 뜨고 밑에 hp가 있는것을 볼 수 있다.
	/*int32 hp = 100;
	UPROPERTY(VisibleAnywhere)
	int32 mp = 50;
	UPROPERTY(VisibleAnywhere)
	int32 Speed = 3.5f;*/

	// UPROPERTY(VisibleAnywhere) 이런식으로 UPROPERTY에 VisibleAnywhere를 넣어주면
	// 에디터 상에서 액터의 멤버변수를 볼수 있다. 하지만 수정은 불가능하다.
	// 수정도 가능하게 하고싶으면 EditAnywhere를 넣어준다. 더 다양한 인수들을 보고싶으면
	// 구글에 Property Specifier라고 검색해서 언리얼 공식 문서에서 확인해보면 된다.

	// 블루프린트와 c++랑 같이 작업을 할때 알아야 할것
	// 1. 사소하게 코드 상에서 변수의 수치만 바꿔도 다시 컴파일을 해야한다.
	// 물론 꺼지는 것까지 안가게 하기 위해서 조금 불안정하긴 하지만 ctrl + alt + F11을 눌러서 라이브 코딩을 이용해서 하면 바뀐게 반영이 된다. 
	// 하지만 매번 이렇게 빌드를 해야한다는 점이 굉장히 부담이 될수있는 작업이다

	// 2. 블루프린트의 가장 큰 장점은, c++로 코드상에서 작업할때 리소스랑 관련된 작업을 할때 리소스를 연결할때 코드로 만드는건 너무 힘들것이다.
	// 근데 에디터 상에서 블루프린트 클래스를 하나 만들어서 
	// 우리가 만들었던 c++ 클래스를 상속받아서 에디터의 블루프린트 클래스를 만들수 있다. 
	// 블루프린트 클래스는 블루프린트 클래스를 상속받아 만들수 있고 C++클래스를 상속받아서 만들수도 있다.
	// 근데 c++클래스는 블루 프린트 클래스를 상속받아서 못만든다, One-Way이다.
	// 그래서 결국에 c++클래스를 상속받아서 블루프린트 클래스를 만들면 
	// 블루프린트 클래스를 비주얼 라이징해서 볼수있다. 만약 어떤 기사 같은 모양의 아트 리소스를 포함시킨다고 하면
	// 에디터에서 편하게 볼수 있고, details에서 편하게 수정할수있다.

	// 그래서 c++은 빠르니까, 핵심 로직은 C++에 넣어놓고 아트 리소스를 연결하거나하는 부분들은 블루 프린트에서 관리를 한다면
	// 나름대로 양쪽의 장점을 다 얻어올 수 있다.
	// 그리고 뿐만 아니라 블루프린트에 Event Graph에서 여러가지 새로운 기능을 만들어 본다거나 해서 간단하게 테스트 할 수 있다는게 큰 장점이다.

	
};

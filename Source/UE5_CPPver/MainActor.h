// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainActor.generated.h"



class AR1Actor;

UCLASS()
class UE5_CPPVER_API AMainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	TObjectPtr<AR1Actor> Actor;
	
	// TSubclassOf는 R1 Actor를 상속받은 것을 여기다가 담아줄 수 있는 굉장히 특이한 타입이라고 보면 된다.
	TSubclassOf<AR1Actor> ActorClass; // BP_R1Actor
};

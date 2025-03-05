// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "R1PlayerController.generated.h"

struct FInputActionValue;
// 구조체는 클래스와 차이가 거의없기 때문에 전방선언을 할 때 구조체타입으로 선언해줘도된다.
/**
 * 
 */
UCLASS()
class UE5_CPPVER_API AR1PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AR1PlayerController(const FObjectInitializer& ObjectInitializer);
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void Input_Test(const FInputActionValue& InputValue);
	void Input_Move(const FInputActionValue& InputValue);
	void Input_Turn(const FInputActionValue& InputValue);

protected:
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> TestAction;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> TurnAction;
};

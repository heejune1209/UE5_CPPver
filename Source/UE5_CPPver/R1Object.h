// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "R1Object.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPPVER_API UR1Object : public UObject
{
	GENERATED_BODY()

	
protected:
	int32 hp = 100;
	int32 mp = 50;
	float Speed = 3.5f;
};

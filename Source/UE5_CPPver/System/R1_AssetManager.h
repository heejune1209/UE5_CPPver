// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "R1_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPPVER_API UR1_AssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	UR1_AssetManager();

	static UR1_AssetManager& Get();
};

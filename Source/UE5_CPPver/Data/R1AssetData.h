// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "R1AssetData.generated.h"

USTRUCT()
struct FAssetEntry
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	FName Name;

	UPROPERTY(EditDefaultsOnly)
	FSoftObjectPath AssetPath;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<FName> AssetLabels;

};

USTRUCT()
struct FAssetSet
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FAssetEntry> AssetEntries;
};
/**
 * 
 */
UCLASS()
class UE5_CPPVER_API UR1AssetData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FName, FAssetSet> AssetGroupNameToset;

};

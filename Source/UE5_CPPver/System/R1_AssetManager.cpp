#include "R1_AssetManager.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "System/R1_AssetManager.h"
#include "R1LogChannels.h"

UR1_AssetManager::UR1_AssetManager() : Super()
{

}

UR1_AssetManager& UR1_AssetManager::Get()
{
	if (UR1_AssetManager* Singleton = Cast<UR1_AssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}
	
	UE_LOG(LogUE5_CPPver, Fatal, TEXT("Can't Find AssetManager"));
	return *NewObject<UR1_AssetManager>();
}

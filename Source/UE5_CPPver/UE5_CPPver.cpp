// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_CPPver.h"
#include "Modules/ModuleManager.h"
#include "R1LogChannels.h"

class FRIModule : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		//UE_LOG(LogTemp, Log, TEXT("Hello World"));
		UE_LOG(LogUE5_CPPver, Log, TEXT("Hello World"));
	}
	virtual void ShutdownModule() override
	{

	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FRIModule, UE5_CPPver, "UE5_CPPver" );

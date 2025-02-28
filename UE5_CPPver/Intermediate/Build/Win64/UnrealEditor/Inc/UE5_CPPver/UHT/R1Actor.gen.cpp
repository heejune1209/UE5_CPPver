// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE5_CPPver/R1Actor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeR1Actor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
UE5_CPPVER_API UClass* Z_Construct_UClass_AR1Actor();
UE5_CPPVER_API UClass* Z_Construct_UClass_AR1Actor_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE5_CPPver();
// End Cross Module References

// Begin Class AR1Actor
void AR1Actor::StaticRegisterNativesAR1Actor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AR1Actor);
UClass* Z_Construct_UClass_AR1Actor_NoRegister()
{
	return AR1Actor::StaticClass();
}
struct Z_Construct_UClass_AR1Actor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "R1Actor.h" },
		{ "ModuleRelativePath", "R1Actor.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AR1Actor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AR1Actor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_UE5_CPPver,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AR1Actor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AR1Actor_Statics::ClassParams = {
	&AR1Actor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AR1Actor_Statics::Class_MetaDataParams), Z_Construct_UClass_AR1Actor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AR1Actor()
{
	if (!Z_Registration_Info_UClass_AR1Actor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AR1Actor.OuterSingleton, Z_Construct_UClass_AR1Actor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AR1Actor.OuterSingleton;
}
template<> UE5_CPPVER_API UClass* StaticClass<AR1Actor>()
{
	return AR1Actor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AR1Actor);
AR1Actor::~AR1Actor() {}
// End Class AR1Actor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_UE5_CPPver_UE5_CPPver_Source_UE5_CPPver_R1Actor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AR1Actor, AR1Actor::StaticClass, TEXT("AR1Actor"), &Z_Registration_Info_UClass_AR1Actor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AR1Actor), 1193714794U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_UE5_CPPver_UE5_CPPver_Source_UE5_CPPver_R1Actor_h_3457068767(TEXT("/Script/UE5_CPPver"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_UE5_CPPver_UE5_CPPver_Source_UE5_CPPver_R1Actor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_UE5_CPPver_UE5_CPPver_Source_UE5_CPPver_R1Actor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

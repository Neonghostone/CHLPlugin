// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CHLCleanWindow/Public/MyLevelInstanceSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyLevelInstanceSubsystem() {}
// Cross Module References
	CHLCLEANWINDOW_API UClass* Z_Construct_UClass_UMyLevelInstanceSubsystem();
	CHLCLEANWINDOW_API UClass* Z_Construct_UClass_UMyLevelInstanceSubsystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_CHLCleanWindow();
// End Cross Module References
	void UMyLevelInstanceSubsystem::StaticRegisterNativesUMyLevelInstanceSubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyLevelInstanceSubsystem);
	UClass* Z_Construct_UClass_UMyLevelInstanceSubsystem_NoRegister()
	{
		return UMyLevelInstanceSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UMyLevelInstanceSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyLevelInstanceSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_CHLCleanWindow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLevelInstanceSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MyLevelInstanceSubsystem.h" },
		{ "ModuleRelativePath", "Public/MyLevelInstanceSubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyLevelInstanceSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyLevelInstanceSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyLevelInstanceSubsystem_Statics::ClassParams = {
		&UMyLevelInstanceSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMyLevelInstanceSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyLevelInstanceSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyLevelInstanceSubsystem()
	{
		if (!Z_Registration_Info_UClass_UMyLevelInstanceSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyLevelInstanceSubsystem.OuterSingleton, Z_Construct_UClass_UMyLevelInstanceSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyLevelInstanceSubsystem.OuterSingleton;
	}
	template<> CHLCLEANWINDOW_API UClass* StaticClass<UMyLevelInstanceSubsystem>()
	{
		return UMyLevelInstanceSubsystem::StaticClass();
	}
	UMyLevelInstanceSubsystem::UMyLevelInstanceSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyLevelInstanceSubsystem);
	UMyLevelInstanceSubsystem::~UMyLevelInstanceSubsystem() {}
	struct Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyLevelInstanceSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyLevelInstanceSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyLevelInstanceSubsystem, UMyLevelInstanceSubsystem::StaticClass, TEXT("UMyLevelInstanceSubsystem"), &Z_Registration_Info_UClass_UMyLevelInstanceSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyLevelInstanceSubsystem), 3956682502U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyLevelInstanceSubsystem_h_2227853808(TEXT("/Script/CHLCleanWindow"),
		Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyLevelInstanceSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyLevelInstanceSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

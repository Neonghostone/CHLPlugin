// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CHLCleanWindow/Public/CHLMyEngineSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCHLMyEngineSubsystem() {}
// Cross Module References
	CHLCLEANWINDOW_API UClass* Z_Construct_UClass_UCHLMyEngineSubsystem();
	CHLCLEANWINDOW_API UClass* Z_Construct_UClass_UCHLMyEngineSubsystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UEngineSubsystem();
	UPackage* Z_Construct_UPackage__Script_CHLCleanWindow();
// End Cross Module References
	void UCHLMyEngineSubsystem::StaticRegisterNativesUCHLMyEngineSubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCHLMyEngineSubsystem);
	UClass* Z_Construct_UClass_UCHLMyEngineSubsystem_NoRegister()
	{
		return UCHLMyEngineSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UCHLMyEngineSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCHLMyEngineSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEngineSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_CHLCleanWindow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCHLMyEngineSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Create struct with @ Actions @ 1 Mem * Actor 2 Mem * Move ... examples\n * \n */" },
		{ "IncludePath", "CHLMyEngineSubsystem.h" },
		{ "ModuleRelativePath", "Public/CHLMyEngineSubsystem.h" },
		{ "ToolTip", "Create struct with @ Actions @ 1 Mem * Actor 2 Mem * Move ... examples" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCHLMyEngineSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCHLMyEngineSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCHLMyEngineSubsystem_Statics::ClassParams = {
		&UCHLMyEngineSubsystem::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCHLMyEngineSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCHLMyEngineSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCHLMyEngineSubsystem()
	{
		if (!Z_Registration_Info_UClass_UCHLMyEngineSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCHLMyEngineSubsystem.OuterSingleton, Z_Construct_UClass_UCHLMyEngineSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCHLMyEngineSubsystem.OuterSingleton;
	}
	template<> CHLCLEANWINDOW_API UClass* StaticClass<UCHLMyEngineSubsystem>()
	{
		return UCHLMyEngineSubsystem::StaticClass();
	}
	UCHLMyEngineSubsystem::UCHLMyEngineSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCHLMyEngineSubsystem);
	UCHLMyEngineSubsystem::~UCHLMyEngineSubsystem() {}
	struct Z_CompiledInDeferFile_FID_VideoGameProjects_UE_Ue5_UnrealEngine5_2_CHLClean_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLMyEngineSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_VideoGameProjects_UE_Ue5_UnrealEngine5_2_CHLClean_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLMyEngineSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCHLMyEngineSubsystem, UCHLMyEngineSubsystem::StaticClass, TEXT("UCHLMyEngineSubsystem"), &Z_Registration_Info_UClass_UCHLMyEngineSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCHLMyEngineSubsystem), 4225911900U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_VideoGameProjects_UE_Ue5_UnrealEngine5_2_CHLClean_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLMyEngineSubsystem_h_3312220668(TEXT("/Script/CHLCleanWindow"),
		Z_CompiledInDeferFile_FID_VideoGameProjects_UE_Ue5_UnrealEngine5_2_CHLClean_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLMyEngineSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_VideoGameProjects_UE_Ue5_UnrealEngine5_2_CHLClean_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLMyEngineSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CHLCleanWindow/Public/CHLPluginAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCHLPluginAIController() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	CHLCLEANWINDOW_API UClass* Z_Construct_UClass_ACHLPluginAIController();
	CHLCLEANWINDOW_API UClass* Z_Construct_UClass_ACHLPluginAIController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CHLCleanWindow();
// End Cross Module References
	void ACHLPluginAIController::StaticRegisterNativesACHLPluginAIController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACHLPluginAIController);
	UClass* Z_Construct_UClass_ACHLPluginAIController_NoRegister()
	{
		return ACHLPluginAIController::StaticClass();
	}
	struct Z_Construct_UClass_ACHLPluginAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACHLPluginAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_CHLCleanWindow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACHLPluginAIController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "CHLPluginAIController.h" },
		{ "ModuleRelativePath", "Public/CHLPluginAIController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACHLPluginAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACHLPluginAIController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACHLPluginAIController_Statics::ClassParams = {
		&ACHLPluginAIController::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACHLPluginAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACHLPluginAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACHLPluginAIController()
	{
		if (!Z_Registration_Info_UClass_ACHLPluginAIController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACHLPluginAIController.OuterSingleton, Z_Construct_UClass_ACHLPluginAIController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACHLPluginAIController.OuterSingleton;
	}
	template<> CHLCLEANWINDOW_API UClass* StaticClass<ACHLPluginAIController>()
	{
		return ACHLPluginAIController::StaticClass();
	}
	ACHLPluginAIController::ACHLPluginAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACHLPluginAIController);
	ACHLPluginAIController::~ACHLPluginAIController() {}
	struct Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLPluginAIController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLPluginAIController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACHLPluginAIController, ACHLPluginAIController::StaticClass, TEXT("ACHLPluginAIController"), &Z_Registration_Info_UClass_ACHLPluginAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACHLPluginAIController), 3003260327U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLPluginAIController_h_1656079396(TEXT("/Script/CHLCleanWindow"),
		Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLPluginAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_CHLPluginAIController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

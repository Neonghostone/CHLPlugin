// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CHLCleanWindow/Public/MyWorldSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyWorldSubsystem() {}
// Cross Module References
	CHLCLEANWINDOW_API UClass* Z_Construct_UClass_UMyWorldSubsystem();
	CHLCLEANWINDOW_API UClass* Z_Construct_UClass_UMyWorldSubsystem_NoRegister();
	CHLCLEANWINDOW_API UFunction* Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature();
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	UPackage* Z_Construct_UPackage__Script_CHLCleanWindow();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyWorldSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_CHLCleanWindow, nullptr, "OnWorldBeginPlay__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnWorldBeginPlay_DelegateWrapper(const FMulticastScriptDelegate& OnWorldBeginPlay)
{
	OnWorldBeginPlay.ProcessMulticastDelegate<UObject>(NULL);
}
	void UMyWorldSubsystem::StaticRegisterNativesUMyWorldSubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyWorldSubsystem);
	UClass* Z_Construct_UClass_UMyWorldSubsystem_NoRegister()
	{
		return UMyWorldSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UMyWorldSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnWorldBeginPlayCHL_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnWorldBeginPlayCHL;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyWorldSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_CHLCleanWindow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyWorldSubsystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyWorldSubsystem.h" },
		{ "ModuleRelativePath", "Public/MyWorldSubsystem.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyWorldSubsystem_Statics::NewProp_OnWorldBeginPlayCHL_MetaData[] = {
		{ "Comment", "//FTestDelegate OnTestDelegate;\n" },
		{ "ModuleRelativePath", "Public/MyWorldSubsystem.h" },
		{ "ToolTip", "FTestDelegate OnTestDelegate;" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMyWorldSubsystem_Statics::NewProp_OnWorldBeginPlayCHL = { "OnWorldBeginPlayCHL", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMyWorldSubsystem, OnWorldBeginPlayCHL), Z_Construct_UDelegateFunction_CHLCleanWindow_OnWorldBeginPlay__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMyWorldSubsystem_Statics::NewProp_OnWorldBeginPlayCHL_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyWorldSubsystem_Statics::NewProp_OnWorldBeginPlayCHL_MetaData)) }; // 590877039
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyWorldSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyWorldSubsystem_Statics::NewProp_OnWorldBeginPlayCHL,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyWorldSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyWorldSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyWorldSubsystem_Statics::ClassParams = {
		&UMyWorldSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMyWorldSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyWorldSubsystem_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMyWorldSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyWorldSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyWorldSubsystem()
	{
		if (!Z_Registration_Info_UClass_UMyWorldSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyWorldSubsystem.OuterSingleton, Z_Construct_UClass_UMyWorldSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyWorldSubsystem.OuterSingleton;
	}
	template<> CHLCLEANWINDOW_API UClass* StaticClass<UMyWorldSubsystem>()
	{
		return UMyWorldSubsystem::StaticClass();
	}
	UMyWorldSubsystem::UMyWorldSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyWorldSubsystem);
	UMyWorldSubsystem::~UMyWorldSubsystem() {}
	struct Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyWorldSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyWorldSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyWorldSubsystem, UMyWorldSubsystem::StaticClass, TEXT("UMyWorldSubsystem"), &Z_Registration_Info_UClass_UMyWorldSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyWorldSubsystem), 249617982U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyWorldSubsystem_h_2718875213(TEXT("/Script/CHLCleanWindow"),
		Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyWorldSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_Github_CHLProjectSource_CHLPlugin_Plugins_CHLCleanWindow_Source_CHLCleanWindow_Public_MyWorldSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

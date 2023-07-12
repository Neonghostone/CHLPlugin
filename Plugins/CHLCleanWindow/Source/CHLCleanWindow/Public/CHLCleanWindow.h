// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

//Other
#include "Delegates/Delegate.h"


class FToolBarBuilder;
class FMenuBuilder;
class UMyWorldSubsystem; 
class UMyLevelInstanceSubsystem;



DECLARE_DELEGATE(FDelegateBeginPlay);

//DECLARE_MULTICAST_DELEGATE(FOnWorldBeginPlay); can be of use
//FOnWorldBeginPlay OnWorldBeginPlay;



class FCHLCleanWindowModule : public IModuleInterface
{
public:



	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	void PluginButtonClicked();

	//CHL functions and variables non default

	//Functions
	// 
	//SLATE
	void OnTextCommitted(const FText& InText);
	void OnTextChanged(const FText& InText);
	FReply OnButtonCompileClicked();
	// 
	//OTHER
	void RunScripts (FText pScriptText, int StartIndex); 
	void ProcessKeyWord(FString pScriptWord, int EndPos);
	void HandleCheckIsIfKeywordTagKeyword(FString pKeyWord, TArray<FString> pPreWord, TArray<FString> pPostWord);
	TArray<FString> GetPreWordsOfKeyWord(FString pKeyWord, int pStartingPosition);
	TArray<FString> GetPostWordsOfKeyWord(FString pKeyWord, int pStartingPosition);
	void HandlePawnKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord); //Should be array of keywords later on
	void HandleAtKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord);
	void HandleVectorKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord);
	void HandleLocationKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord);
	void HandleToKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord);
	void RegisterMenus();
	bool bIsVectorOrFloat(FString StringEntering); 
	//Neongho: to get called by delegate
	void OnBeginPlayFunction(); 

	//Vars
	FText ActualScriptText; 
	FString NameOfPlugin = "CHLPluginForUnreal"; 
	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

	//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestDelegate);
	//UPROPERTY(BlueprintAssignable, Category = "Test")
	// 
	// 


	/*
	DECLARE_MULTICAST_DELEGATE(FTestDelegate);
	UPROPERTY(BlueprintAssignable, Category = "Test")
		FTestDelegate StaticDelegateOnWorldInit;
	*/

	//FTestDelegate OnTestDelegate;
	UPROPERTY(BlueprintAssignable)
		FDelegateBeginPlay OnTestBeginPlay;


	//The instance that we have of our world
	UMyWorldSubsystem * MyMyWorldSubsystem;


	//The instance that we have of our world
	UCHLMyEngineSubsystem * MyEngineSubsystem;





private:




private:
	TSharedPtr<class FUICommandList> PluginCommands;
};

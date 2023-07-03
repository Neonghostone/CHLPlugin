// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

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


	//Vars
	FText ActualScriptText; 
	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);
	void RegisterMenus();


private:







private:
	TSharedPtr<class FUICommandList> PluginCommands;
};

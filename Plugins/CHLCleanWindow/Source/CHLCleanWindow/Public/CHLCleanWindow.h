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
	void RunScripts(FText pScriptText, int StartIndex); 
	void ProcessKeyWord(FString pScriptWord); 

	//Vars
	FText ActualScriptText; 

private:

	void RegisterMenus();

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);



private:
	TSharedPtr<class FUICommandList> PluginCommands;
};

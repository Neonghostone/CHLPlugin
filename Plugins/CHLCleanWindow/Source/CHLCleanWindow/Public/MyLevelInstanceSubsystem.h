// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyLevelInstanceSubsystem.generated.h"

class UCHLMyEngineSubsystem;
/**
 * 
 */
UCLASS()
class CHLCLEANWINDOW_API UMyLevelInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public: 
	//Functions
	void Initialize(FSubsystemCollectionBase& Collection);

	//Vars SHOULD MOVE MOST IN MODULE
	int32 PersIntOfSubsystem;
	FString ActualModuleCHLScripts; 
	FText ActualModuleCHLScriptsTextV;
	UCHLMyEngineSubsystem* CHLEngineSubsystem;
	TArray<ActionsPerActor> ActionsOfStory;

	//Functs SHOULD MOVE IN MODULE
	TArray<ActionsPerActor> CreateAllActionsThroughScripts(FString pScripts); //Maybe it is better to create actions from module or use an ID when actor spawned
	void RunScriptsOnRunningLevel(FText pScriptText, int StartIndex);
	void ProcessKeyWordOnRunningLevel(FString pScriptWord, int EndPos);
	void HandleCheckIsIfKeywordTagKeywordOnRunningLevel(FString pKeyWord, TArray<FString> pPreWord, TArray<FString> pPostWord);
	TArray<FString> GetPreWordsOfKeyWordOnRunningLevel(FString pKeyWord, int pStartingPosition);
	TArray<FString> GetPostWordsOfKeyWordOnRunningLevel(FString pKeyWord, int pStartingPosition);
	void HandlePawnKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord); //Should be array of keywords later on
	void HandleAtKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord);
	void HandleVectorKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord);
	void HandleLocationKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord);
	void HandleToKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord);


};

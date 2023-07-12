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

	//Vars
	int32 PersIntOfSubsystem;

	FString ActualModuleCHLScripts; 

	UCHLMyEngineSubsystem* CHLEngineSubsystem;

	TArray<ActionsPerActor> ActionsOfStory;

	TArray<ActionsPerActor> CreateAllActionsThroughScripts();
};

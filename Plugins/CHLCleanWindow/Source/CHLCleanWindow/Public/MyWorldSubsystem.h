// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CHLCleanWindow.h"
#include "MyWorldSubsystem.generated.h"

class UCHLMyEngineSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWorldBeginPlay);

UCLASS()
class CHLCLEANWINDOW_API UMyWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:

	//Functions
	void Initialize(FSubsystemCollectionBase& Collection);

	void PrintMeMessageFromHere(); 

	static UMyWorldSubsystem* Get(const UWorld* const InWorld) {return InWorld ? InWorld->GetSubsystem<UMyWorldSubsystem>() : nullptr;}

	void ReceiveTheModuleRef(FCHLCleanWindowModule* ThePLuginModule);


	//Vars
	FString ActualScriptsToRun;

	//FTestDelegate OnTestDelegate;
	UPROPERTY(BlueprintAssignable)
		FOnWorldBeginPlay OnWorldBeginPlayCHL;

	FCHLCleanWindowModule* CHLPluginModule; 

	UCHLMyEngineSubsystem * MyEngineSubsystemFromWorldSubsystem; 

};



// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "CHLMyEngineSubsystem.generated.h"

enum ActionKind
{
	EN_MoveTo,
	EN_Follow,
	EN_PlaySpecificAnimation,
};

struct ActionOfStoryOfActor
{
	ActionKind KindOfStoryActionToDo;
	float TimeToDoThatAction;
	FVector3d PointToGoOrElse;
};

struct ActionsPerActor
{
	TArray<ActionOfStoryOfActor> ActionOfStoryOfActor;
	AActor* ActorBindToAction;
};



/**
 * Create struct with @ Actions @ 1 Mem * Actor 2 Mem * Move ... examples
 * 
 */
UCLASS()
class CHLCLEANWINDOW_API UCHLMyEngineSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	//Functions
	void Initialize(FSubsystemCollectionBase& Collection);

	//Vars
	int32 PersIntOfSubsystem; 
	FString PersistentScriptsText;

};

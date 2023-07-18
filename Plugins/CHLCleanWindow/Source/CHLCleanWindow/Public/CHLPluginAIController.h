// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CHLPluginAIController.generated.h"

/**
 * 
 */
UCLASS()
class CHLCLEANWINDOW_API ACHLPluginAIController : public AAIController
{
	GENERATED_BODY()

public: 
	//Functs

	void BeginPlay();

	void MovementTick();


	//Vars

	FVector3d Destination; 

	FTimerHandle MovementTimerHandle;
};

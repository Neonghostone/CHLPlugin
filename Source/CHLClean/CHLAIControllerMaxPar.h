// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CHLAIControllerMaxPar.generated.h"

/**
 * 
 */
UCLASS()
class CHLCLEAN_API ACHLAIControllerMaxPar : public AAIController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		float MaxTimerDelay;

	FTimerHandle MovementTimerHandle;

	ACHLAIControllerMaxPar();

	void BeginPlay();

	void MovementTick();
};

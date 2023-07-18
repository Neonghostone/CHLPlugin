// Fill out your copyright notice in the Description page of Project Settings.


#include "CHLPluginAIController.h"

void ACHLPluginAIController::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(MovementTimerHandle, this, &ACHLPluginAIController::MovementTick, 3.0, true);
	//Destination = GetPawn()->GetActorLocation();
}

void ACHLPluginAIController::MovementTick()
{
	UE_LOG(LogTemp, Warning, TEXT("FROM ACHLPluginAIController PLugin ai movement tick %s "), *Destination.ToString()); 
	UE_LOG(LogTemp, Warning, TEXT("FROM ACHLPluginAIController Possessed pawn is %s "), *GetPawn()->GetName()); 

	MoveToLocation(Destination,-1.0, true, false);
}



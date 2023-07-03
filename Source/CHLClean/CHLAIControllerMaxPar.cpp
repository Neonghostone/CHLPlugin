// Fill out your copyright notice in the Description page of Project Settings.


#include "CHLAIControllerMaxPar.h"

ACHLAIControllerMaxPar::ACHLAIControllerMaxPar()
{


}

void ACHLAIControllerMaxPar::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(MovementTimerHandle, this, &ACHLAIControllerMaxPar::MovementTick, 3.0, true);
}

void ACHLAIControllerMaxPar::MovementTick()
{
	FVector3d ExtraVector; 

	ExtraVector.X = 100; 
	ExtraVector.Y = 100;
	ExtraVector.Z = 0;

	UE_LOG(LogTemp, Warning, TEXT(" FROM AI ticking %s"),  *GetPawn()->GetName()  );
	
	MoveToLocation( this->GetPawn()->GetActorLocation() + ExtraVector );
	
}
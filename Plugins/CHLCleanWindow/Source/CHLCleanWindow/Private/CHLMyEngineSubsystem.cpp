// Fill out your copyright notice in the Description page of Project Settings.


#include "CHLMyEngineSubsystem.h"

void UCHLMyEngineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{

	UE_LOG(LogTemp, Warning, TEXT("FROM Engine system This is a begin play from the whole game ************"));
	PersIntOfSubsystem++; 
	
	UE_LOG(LogTemp, Warning, TEXT("FROM Engine system This is a begin play from the whole game ************ int is %i "), PersIntOfSubsystem);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelInstanceSubsystem.h"
#include "CHLMyEngineSubsystem.h"


void UMyLevelInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{

	UE_LOG(LogTemp, Warning, TEXT("FROM GAME system This is a begin play from the whole game ************"));
	PersIntOfSubsystem++;
	UE_LOG(LogTemp, Warning, TEXT("FROM GAME system This is a begin play from the whole game ************ int is %i "), PersIntOfSubsystem);
	CHLEngineSubsystem = GEngine->GetEngineSubsystem<UCHLMyEngineSubsystem>();
	ActualModuleCHLScripts = *CHLEngineSubsystem->PersistentScriptsText; 
	UE_LOG(LogTemp, Warning, TEXT("FROM GAME system This is a begin play from the whole game SCRIPTS ARE ************ int is %s "), *ActualModuleCHLScripts);

}

TArray<ActionsPerActor> UMyLevelInstanceSubsystem::CreateAllActionsThroughScripts()
{
	return TArray<ActionsPerActor>();
}

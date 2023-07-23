// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelInstanceSubsystem.h"
#include "CHLMyEngineSubsystem.h"
#include "Kismet/GameplayStatics.h"
//#include "CHLAIControllerMaxPar.h"
#include "CHLPluginAIController.h"

void UMyLevelInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	TArray<ActionsPerActor> ActionsToRunNowOnLevel;
	TArray<AActor*> AllActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), AllActors);

	

	UE_LOG(LogTemp, Warning, TEXT("FROM GAME system This is a begin play from the whole game ************"));
	PersIntOfSubsystem++;
	UE_LOG(LogTemp, Warning, TEXT("FROM GAME system This is a begin play from the whole game ************ int is %i "), PersIntOfSubsystem);
	CHLEngineSubsystem = GEngine->GetEngineSubsystem<UCHLMyEngineSubsystem>();
	ActualModuleCHLScripts = *CHLEngineSubsystem->PersistentScriptsText; 
	ActualModuleCHLScriptsTextV = CHLEngineSubsystem->PersistentScriptsTextV;
	UE_LOG(LogTemp, Warning, TEXT("FROM GAME system This is a begin play from the whole game SCRIPTS ARE ************ int is %s "), *ActualModuleCHLScripts);
	//CreateAllActionsThroughScripts(CHLEngineSubsystem->PersistentScriptsText);


	ActionsToRunNowOnLevel = CHLEngineSubsystem->ActionsToProcessOnLevelStart; 

	UE_LOG(LogTemp, Warning, TEXT("FROM GAME the actions you want to process are ***** %i "), ActionsToRunNowOnLevel.Num());
	

	/*
	if (ActionsToRunNowOnLevel.Num() > 0)
	{
		ActionsToRunNowOnLevel[0].ActorBindToAction; 
		//ActionsToRunNowOnLevel[0].ActorBindToAction->Destroy(); 
		UE_LOG(LogTemp, Warning, TEXT("FROM GAME the the actor to move is %s "), *ActionsToRunNowOnLevel[0].ActorBindToAction->GetName());


		for (int32 i = 0; i < AllActors.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("FROM GAME RADAR ************ ACTOR FOUND == %s "), *AllActors[i]->GetName());

			if (AllActors[i]->GetName() == ActionsToRunNowOnLevel[0].ActorBindToAction->GetName())
			{
				UE_LOG(LogTemp, Warning, TEXT("FROM GAME the the actor to move is ************ ACTOR FOUND == %s "), *ActionsToRunNowOnLevel[0].ActorBindToAction->GetName());

				APawn * CastPawn = Cast<APawn>(AllActors[i]);
				ACHLPluginAIController* CHLAIController;

				CastPawn->GetController(); 

				CHLAIController = Cast<ACHLPluginAIController>(CastPawn->GetController());

				CHLAIController->Destination = ActionsToRunNowOnLevel[0].ActionOfStoryOfActor[0].PointToGoOrElse; 
			}
		}
	}
	*/

	for (int32 i = 0; i < ActionsToRunNowOnLevel.Num(); i++)
	{
		for (int32 i2 = 0; i2 < AllActors.Num(); i2++)
		{
			UE_LOG(LogTemp, Warning, TEXT("FROM GAME RADAR ************ ACTOR FOUND == %s "), *AllActors[i2]->GetName());

			if (AllActors[i2]->GetName() == ActionsToRunNowOnLevel[i].ActorBindToAction->GetName())
			{
				UE_LOG(LogTemp, Warning, TEXT("FROM GAME the the actor to move is ************ ACTOR FOUND == %s "), *ActionsToRunNowOnLevel[i].ActorBindToAction->GetName());

				APawn* CastPawn = Cast<APawn>(AllActors[i2]);
				ACHLPluginAIController* CHLAIController;

				CastPawn->GetController();

				CHLAIController = Cast<ACHLPluginAIController>(CastPawn->GetController());

				CHLAIController->Destination = ActionsToRunNowOnLevel[i].ActionOfStoryOfActor[0].PointToGoOrElse;
			}
		}
	}







	UE_LOG(LogTemp, Warning, TEXT("FROM GAME the actions you want to process are ***** %i "), ActionsToRunNowOnLevel.Num());

}

TArray<ActionsPerActor> UMyLevelInstanceSubsystem::CreateAllActionsThroughScripts(FString pScripts)
{
	UE_LOG(LogTemp, Warning, TEXT("FROM GAME system This is a begin play from the whole game SCRIPTS ARE ************ int is %s "), *pScripts);

	RunScriptsOnRunningLevel(ActualModuleCHLScriptsTextV, 0);

	return TArray<ActionsPerActor>();
}

void UMyLevelInstanceSubsystem::RunScriptsOnRunningLevel(FText pScriptText, int StartIndex)
{
	FText ScriptToConvertToString = pScriptText;
	FString SomeString = ScriptToConvertToString.ToString();
	FString LetterDetected;
	FString WordKeyWordDetected;


}

void UMyLevelInstanceSubsystem::ProcessKeyWordOnRunningLevel(FString pScriptWord, int EndPos)
{
}

void UMyLevelInstanceSubsystem::HandleCheckIsIfKeywordTagKeywordOnRunningLevel(FString pKeyWord, TArray<FString> pPreWord, TArray<FString> pPostWord)
{
}

TArray<FString> UMyLevelInstanceSubsystem::GetPreWordsOfKeyWordOnRunningLevel(FString pKeyWord, int pStartingPosition)
{
	return TArray<FString>();
}

TArray<FString> UMyLevelInstanceSubsystem::GetPostWordsOfKeyWordOnRunningLevel(FString pKeyWord, int pStartingPosition)
{
	return TArray<FString>();
}

void UMyLevelInstanceSubsystem::HandlePawnKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
}

void UMyLevelInstanceSubsystem::HandleAtKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
}

void UMyLevelInstanceSubsystem::HandleVectorKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
}

void UMyLevelInstanceSubsystem::HandleLocationKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
}

void UMyLevelInstanceSubsystem::HandleToKeywordOnRunningLevel(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
}

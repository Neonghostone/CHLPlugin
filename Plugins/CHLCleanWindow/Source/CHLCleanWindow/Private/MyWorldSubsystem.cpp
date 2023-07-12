// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWorldSubsystem.h"
#include "CHLCleanWindow.h"
#include "CHLMyEngineSubsystem.h"

void UMyWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogTemp, Warning, TEXT("FROM World subystem plugin this is begin play"));
	UE_LOG(LogTemp, Warning, TEXT("FROM World subsystem plugin this is begin play text is %s"), *ActualScriptsToRun);

	if( CHLPluginModule != nullptr )
	{
		UE_LOG(LogTemp, Warning, TEXT("FROM World subsystem plugin the plugin is %s"), *CHLPluginModule->NameOfPlugin);
	}

	OnWorldBeginPlayCHL.Broadcast();
	MyEngineSubsystemFromWorldSubsystem = GEngine->GetEngineSubsystem<UCHLMyEngineSubsystem>();

	UE_LOG(LogTemp, Warning, TEXT("FROM World subsystem PLUGIN the text of the engine module is %s"), *MyEngineSubsystemFromWorldSubsystem->PersistentScriptsText);

}

void UMyWorldSubsystem::PrintMeMessageFromHere()
{
	if (CHLPluginModule != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("FROM World I get called %s"), *ActualScriptsToRun);
	}
}

void UMyWorldSubsystem::ReceiveTheModuleRef(FCHLCleanWindowModule* ThePLuginModule)
{

	if (CHLPluginModule == nullptr)
	{
		CHLPluginModule = ThePLuginModule;
		UE_LOG(LogTemp, Warning, TEXT("FROM World subsystem ASSIGNING plugin the plugin is %s"), *CHLPluginModule->NameOfPlugin);
	} 
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "CHLCleanGameModeBase.h"
#include "CHLTestPawnMaxPar.h"

ACHLCleanGameModeBase::ACHLCleanGameModeBase()
{
	
	FString bpResourcePawn = "/Game/CreativeHistoryLangangeContent/CHLPawnDefaultToTest.CHLPawnDefaultToTest";
	
	UBlueprint* GeneratedBPPawn = Cast<UBlueprint>(StaticLoadObject(UObject::StaticClass(), NULL, *bpResourcePawn));

	DefaultPawnClass = GeneratedBPPawn->GeneratedClass;

}
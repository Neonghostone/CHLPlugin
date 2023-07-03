// Fill out your copyright notice in the Description page of Project Settings.


#include "CHLTestPawnMaxPar.h"

// Sets default values
ACHLTestPawnMaxPar::ACHLTestPawnMaxPar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SkeletalMeshOfPawn = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("StotyPawnMesh"));

}

// Called when the game starts or when spawned
void ACHLTestPawnMaxPar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACHLTestPawnMaxPar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACHLTestPawnMaxPar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


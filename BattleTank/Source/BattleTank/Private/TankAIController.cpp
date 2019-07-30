// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

ATankAIController::ATankAIController() 
{

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetPlayerTank()) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller possesed in %s"), *GetPlayerTank()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possesed"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) 
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	APawn* Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!Pawn) { return nullptr; }
	return Cast<ATank>(Pawn);
}

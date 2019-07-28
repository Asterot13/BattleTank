// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetControlledTank()) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay!"));

		UE_LOG(LogTemp, Warning, TEXT("Controlled tank is - %s"), *GetControlledTank()->GetName());
	}
}

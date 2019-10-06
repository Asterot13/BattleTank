// Copyright by Vitaliy Novoselov 2019.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "AssertionMacros.h"
#include "Engine/World.h"

APawn* ATankPlayerController::GetControlledTank() const
{
	return GetPawn();
}

bool ATankPlayerController::GetRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		GetLookVectorHitDirection(LookDirection, OutHitLocation);
		return true;
	}

	OutHitLocation = FVector(0);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitDirection(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		) 
	{
		HitLocation = HitResult.Location;
		return true;
	}

	return false;
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; } // e.g. if not possessing

	UTankAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(GetControlledTank())) { return; }

	FVector HitLocation;
	if (GetRayHitLocation(HitLocation)) 
	{
		AimingComponent->AimAt(HitLocation);
	}
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UTankAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (AimingComponent)
	{
		FoundAimingComponent(AimingComponent);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController can`t find aiming"));
	}
}

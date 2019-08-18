// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//
	virtual void BeginPlay() override;
	//
	virtual void Tick(float DeltaSeconds) override;

protected:
	//
	ATank* GetControlledTank() const;
	//
	bool GetRayHitLocation(FVector& OutHitLocation) const;
	//
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	//
	bool GetLookVectorHitDirection(FVector LookDirection, FVector& HitLocation) const;
	//
	void AimTowardsCrosshair();

public:
	//
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;
	//
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333f;
	//
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 100000.0f;

};

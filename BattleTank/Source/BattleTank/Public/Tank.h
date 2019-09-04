// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	//
	UTankAimingComponent* TankAimingComponent = nullptr;
	//
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:
	// Sets default values for this pawn's properties
	ATank();
	//
	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	//
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTurretReference(UTankTurret* TurretToSet);
	//
	UFUNCTION(BlueprintCallable)
	void Fire();
	//
	void AimAt(FVector HitLocation);

public:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0f;
	//
	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3.0f;
	//
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	//
	UTankBarrel* Barrel;
	//
	UTankTurret* Turret;
	//
	double LastFireTime = 0;

};

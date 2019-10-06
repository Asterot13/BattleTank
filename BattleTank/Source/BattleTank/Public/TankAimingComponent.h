// Copyright by Vitaliy Novoselov 2019.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	//
	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
	//
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

public:	
	//
	void AimAt(FVector HitLocation);
	//
	void MoveBarrel(FVector Direction);

private:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//
	bool IsBarrelMoving();

private:
	//
	UTankBarrel* Barrel;
	//
	UTankTurret* Turret;
	//
	FVector AimDirection;
	//
	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3.0f;
	//
	double LastFireTime = 0;
	//
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0f;
	//
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
};

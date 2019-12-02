// Copyright by Vitaliy Novoselov 2019.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Public/Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	//
	ATankAIController();
	
protected:
	//
	virtual void BeginPlay() override;
	//
	virtual void SetPawn(APawn* InPawn) override;
	//
	virtual void Tick(float DeltaTime) override;
	//
	UFUNCTION()
	void OnPossesedTankDeath();
	//How close AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 6000;

};

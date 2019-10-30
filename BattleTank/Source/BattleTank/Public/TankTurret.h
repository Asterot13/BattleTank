// Copyright by Vitaliy Novoselov 2019.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//
	void Rotate(float DegreesPerSecond);

private:
	//
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 25.0f;

};

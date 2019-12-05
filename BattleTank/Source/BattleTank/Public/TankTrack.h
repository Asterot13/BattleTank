// Copyright by Vitaliy Novoselov 2019.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	//
	UTankTrack();
	//
	void DriveTrack(float CurrentThrottle);
	//
	TArray<class ASprungWheel*> GetWheels() const;

public:

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 500000; //30 000 000

};

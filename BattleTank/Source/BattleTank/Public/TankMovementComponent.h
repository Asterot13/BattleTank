// Copyright by Vitaliy Novoselov 2019.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible from driving the tank tracks
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	//
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTrack* leftTrackToSet, UTankTrack* rightTrackToSet);
	//
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);
	//
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveBackward(float Throw);
	//
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendRotateRight(float Throw);
	//
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	//
	UTankTrack* LeftTrack = nullptr;
	//
	UTankTrack* RightTrack = nullptr;
	
};

// Copyright by Vitaliy Novoselov 2019.

#include "TankTurret.h"

void UTankTurret::Rotate(float DegreesPerSecond)
{
	//UE_LOG(LogTemp, Warning, TEXT("Tank barrel elevate with seconds - %f"), GetWorld()->DeltaTimeSeconds);
	float RelativeSpeed = FMath::Clamp<float>(DegreesPerSecond, -1.0f, 1.0f);
	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));
}
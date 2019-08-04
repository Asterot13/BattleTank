// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float Degrees) 
{
	//UE_LOG(LogTemp, Warning, TEXT("Tank barrel elevate with seconds - %f"), GetWorld()->DeltaTimeSeconds);
	float RelativeSpeed = FMath::Clamp<float>(Degrees, -1.0f, 1.0f);
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
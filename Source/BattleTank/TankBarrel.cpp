// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float degreesPerSecond)
{
	degreesPerSecond = FMath::Clamp<float>(degreesPerSecond, -1.0, 1.0);

	float rotationChange = degreesPerSecond * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float newRotationPitch = RelativeRotation.Pitch + rotationChange;
	newRotationPitch = FMath::Clamp(newRotationPitch, minElevationDegrees, maxElevationDegrees);
	SetRelativeRotation(FRotator(newRotationPitch, 0, 0));
}




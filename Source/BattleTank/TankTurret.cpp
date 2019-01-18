// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float relativeRotation)
{
	relativeRotation = FMath::Clamp<float>(relativeRotation, -1, 1);
	float speed = RelativeRotation.Yaw + relativeRotation * 10 * GetWorld()->DeltaTimeSeconds;
	
	SetRelativeRotation(FRotator(0, speed, 0));
}



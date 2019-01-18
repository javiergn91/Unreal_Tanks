// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float throttle)
{
	FVector forceApplied = GetForwardVector() * throttle * movementForce;
	FVector forceLocation = GetComponentLocation();
	UPrimitiveComponent* primitive = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	primitive->AddForceAtLocation(forceApplied, forceLocation);
}



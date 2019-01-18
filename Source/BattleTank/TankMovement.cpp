// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovement.h"
#include "TankTrack.h"

void UTankMovement::IntendMoveForward(float throttle)
{
	leftTrack->SetThrottle(throttle);
	rightTrack->SetThrottle(throttle);
}

void UTankMovement::IntendMoveRight(float throttle)
{
	leftTrack->SetThrottle(throttle);
	rightTrack->SetThrottle(-throttle);
}

void UTankMovement::Initialise(UTankTrack* _leftTrack, UTankTrack* _rightTrack)
{
	leftTrack = _leftTrack;
	rightTrack = _rightTrack;
}

void UTankMovement::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto aiFormardIntention = MoveVelocity.GetSafeNormal();
	auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto dotProduct = FVector::DotProduct(aiFormardIntention, tankForward);
	auto crossProduct = FVector::CrossProduct(aiFormardIntention, tankForward);
	IntendMoveForward(dotProduct);
	IntendMoveRight(crossProduct.Z);
}




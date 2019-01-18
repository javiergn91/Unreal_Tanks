// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovement.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovement : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void IntendMoveForward(float throttle);
	
	UFUNCTION(BlueprintCallable)
	void IntendMoveRight(float throttle);

	UFUNCTION(BlueprintCallable)
	void Initialise(UTankTrack* _leftTrack, UTankTrack* _rightTrack);

	UTankTrack* leftTrack;
	UTankTrack* rightTrack;

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};

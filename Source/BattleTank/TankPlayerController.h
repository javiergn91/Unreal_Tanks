// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& hitLocation) const;
	void BeginPlay() override;
	void Tick(float deltaSeconds) override;

	UPROPERTY(EditAnywhere)
	float crossHairXLocation;

	UPROPERTY(EditAnywhere)
	float crossHairYLocation;

	UPROPERTY(EditAnywhere)
	float lineTraceRange = 1000000;
};

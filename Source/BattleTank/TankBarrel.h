// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float degreesPerSecond);	

	UPROPERTY(EditAnywhere)
	float maxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere)
	float maxElevationDegrees = 40;

	UPROPERTY(EditAnywhere)
	float minElevationDegrees = 0;
};

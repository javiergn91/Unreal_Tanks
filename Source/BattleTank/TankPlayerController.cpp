// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector hitLocation;

	if (GetSightRayHitLocation(hitLocation))
	{
		GetControlledTank()->AimAt(hitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const
{
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation = FVector2D(viewportSizeX * crossHairXLocation, viewportSizeY * crossHairYLocation);

	FVector outWorldLocation, outWorldDirection;
	if (DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, outWorldLocation, outWorldDirection))
	{
		FHitResult outHitResult;
		if (GetWorld()->LineTraceSingleByChannel(
			outHitResult,
			PlayerCameraManager->GetCameraLocation(),
			PlayerCameraManager->GetCameraLocation() + outWorldDirection * lineTraceRange,
			ECollisionChannel::ECC_Visibility))
		{
			hitLocation = outHitResult.Location;
			return true;
		}
	}

	return false;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();
}

void ATankPlayerController::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
	AimTowardsCrosshair();
}

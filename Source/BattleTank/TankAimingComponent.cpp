// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	firingStatus = EFiringStatus::Aiming;
}

void UTankAimingComponent::AimAt(FVector hitLocation, float launchSpeed)
{
	FVector outTossVelocity;

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		outTossVelocity,
		barrel->GetSocketLocation(FName("projectile")),
		hitLocation,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	))
	{
		outTossVelocity = outTossVelocity.GetSafeNormal();
		MoveBarrelTowards(outTossVelocity);
	}


}

void UTankAimingComponent::SetBarrel(UTankBarrel * _barrel)
{
	barrel = _barrel;
}

void UTankAimingComponent::SetTurret(UTankTurret * _turret)
{
	turret = _turret;
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
	FRotator barrelRotator = barrel->GetForwardVector().Rotation();
	FRotator aimRotator = aimDirection.Rotation();
	FRotator deltaRotator = aimRotator - barrelRotator;

	barrel->Elevate(deltaRotator.Pitch);
	turret->Rotate(deltaRotator.Yaw);
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "TankMovement.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::AimAt(FVector hitLocation)
{
	tankAimingComponent->AimAt(hitLocation, launchSpeed);
}

void ATank::SetBarrel(UTankBarrel * barrel)
{
	tankAimingComponent->SetBarrel(barrel);
	this->barrel = barrel;
}

void ATank::SetTurret(UTankTurret * turret)
{
	tankAimingComponent->SetTurret(turret);
}

void ATank::Fire()
{
	bool bCanFire = (FPlatformTime::Seconds() - lastFiringTime) > firingTime;

	if (!bCanFire)
		return;

	lastFiringTime = FPlatformTime::Seconds();

	auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBlueprint, barrel->GetSocketLocation(FName("Projectile")), barrel->GetSocketRotation(FName("Projectile")));
	projectile->LaunchProjectile(launchSpeed);
}

UTankAimingComponent * ATank::GetAimingComponent()
{
	return tankAimingComponent;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "BattleTank.h"
#include "TankTurret.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (ProjectilesLeft == 0)
		FiringState = EFiringState::OutOfAmmo;
	else if ((GetWorld()->GetTimeSeconds() - LastFireTime) < ReloadTimeInSeconds)
		FiringState = EFiringState::Reloading;
	else if (IsMoving())
		FiringState = EFiringState::Aiming;
	else
		FiringState = EFiringState::Locked;	
}

void UTankAimingComponent::Initialise(UTankTurret* TankTurret, UTankBarrel* TankBarrel)
{
	if (!ensure(TankTurret) || !ensure (TankBarrel)) { return; }
	Barrel= TankBarrel;
	Turret = TankTurret;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) {return;}
	if(!ensure(Turret)) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,0,0,
		ESuggestProjVelocityTraceOption::DoNotTrace	
	);
	if (bHaveAimSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal(); // zmieniam dlugi wektor na jednostkowy
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);
	}
	else
		auto Time = GetWorld()->GetTimeSeconds();
	
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) 
{
	if (!ensure(Barrel)) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurret(FVector AimDirection) {

	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	if(FMath::Abs(DeltaRotator.Yaw) < 180)
	Turret->RotateTurret(DeltaRotator.Yaw);
	else
	Turret->RotateTurret(-DeltaRotator.Yaw);
}

void UTankAimingComponent::Fire()
{
	if (Barrel && ProjectileBlueprint) {
		if ((FiringState == EFiringState::Aiming) || FiringState == EFiringState::Locked) {
			auto Projectile = GetWorld()->SpawnActor<AProjectile>(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
				);

			Projectile->LaunchProjectile(LaunchSpeed);
			LastFireTime = GetWorld()->GetTimeSeconds();
			ProjectilesLeft--;
		}
	}
}

bool UTankAimingComponent::IsMoving()
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelForward = Barrel->GetForwardVector();
	return !BarrelForward.Equals(AimDirection, 0.05);
}

EFiringState UTankAimingComponent::GetFiringState()
{
	return FiringState;
}

int UTankAimingComponent::GetProjectilesLeft()
{
	return ProjectilesLeft;	
}

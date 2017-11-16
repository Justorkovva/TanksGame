// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "BattleTank.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	
	//auto TankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s is aiming from %s  at : %s"), *TankName, *BarrelLocation.ToString(), *HitLocation.ToString());
	if (!Barrel) {return;}
	if(!Turret) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		
	);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal(); // zmieniam dlugi wektor na jednostkowy
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);

		//auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT(" %s is firing  at : %s"),*TankName, *AimDirection.ToString());
		//auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f : Aiming with speed "), Time);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f : No aim solve found"), Time);
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) 
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) 
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator : %s"), *DeltaRotator.ToString());

	Barrel->Elevate(DeltaRotator.Pitch);
	
}

void UTankAimingComponent::MoveTurret(FVector AimDirection) {

	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	Turret->RotateTurret(DeltaRotator.Yaw);

	//UE_LOG(LogTemp, Warning, TEXT("Powinno sie obrocic na: %f "), DeltaRotator.Yaw);
}

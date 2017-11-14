// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	
	//auto TankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s is aiming from %s  at : %s"), *TankName, *BarrelLocation.ToString(), *HitLocation.ToString());
	if (!Barrel) {return;}

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(
	this,
	OutLaunchVelocity,	
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false, //highArc
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		)
	) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal(); // zmieniam dlugi wektor na jednostkowy
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT(" %s is firing  at : %s"),*TankName, *AimDirection.ToString());
	}
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {

	Barrel = BarrelToSet;
}

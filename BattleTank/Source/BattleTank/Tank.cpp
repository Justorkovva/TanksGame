#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Gameframework/Actor.h" 

ATank::ATank()
{
 	PrimaryActorTick.bCanEverTick = false;
	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent")); 
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation) 
{
	AimingComponent -> AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	AimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret* TurretToSet) {

	AimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Error, TEXT("FIRE!!!"));
}
#include "Tank.h"

ATank::ATank()
{
 	PrimaryActorTick.bCanEverTick = true;
	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation) 
{
	AimingComponent -> AimAt(HitLocation);
}

void ATank::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	AimingComponent->SetBarrelReference(BarrelToSet);

}


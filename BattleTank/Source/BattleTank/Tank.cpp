#include "Tank.h"
#include "TankBarrel.h"
#include "Gameframework/Actor.h" 
#include "BattleTank.h"
#include "Projectile.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
	//AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent")); dodaje automatycznie do tank_bp
}

void ATank::BeginPlay() 
{
	Super::BeginPlay();
}

void ATank::Fire()
{
	bool IsReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds; //FPlatformTime::Seconds() inna funkcja na czas

	UE_LOG(LogTemp, Warning, TEXT("I'm here"));
	if (Barrel && IsReloaded) {
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}
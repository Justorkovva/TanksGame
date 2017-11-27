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
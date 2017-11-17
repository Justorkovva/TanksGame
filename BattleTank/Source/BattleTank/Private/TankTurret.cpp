
#include "TankTurret.h"
#include "BattleTank.h"

UTankTurret::UTankTurret() { PrimaryComponentTick.bCanEverTick = false; }

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto YawChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewYaw = RelativeRotation.Yaw + YawChange;

	// TODO sprawdzic, bo nie wiadomo czy po 180 idzie dalej
	SetRelativeRotation(FRotator(0, RawNewYaw, 0)); // ustawiam nowa rotacje dla dziala
}
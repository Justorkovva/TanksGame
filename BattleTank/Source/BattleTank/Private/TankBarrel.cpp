
#include "TankBarrel.h"
#include "BattleTank.h"

UTankBarrel::UTankBarrel()
{
	PrimaryComponentTick.bCanEverTick = false;	
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1); // minimalna i maksymalna wartosc

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto Elevation = FMath::Clamp<float>(RawNewElevation, minElevationDegrees, maxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0)); // ustawiam nowa rotacje dla dziala, kolejnosc - Pitch, Yaw, Roll!!
}
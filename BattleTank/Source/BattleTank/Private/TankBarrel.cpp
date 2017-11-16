// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "BattleTank.h"


UTankBarrel::UTankBarrel()
{
	PrimaryComponentTick.bCanEverTick = false;	
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//if (RelativeSpeed > 1) { RelativeSpeed = 1; }
	//if (RelativeSpeed <-1) { RelativeSpeed = -1; }
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	//if(RawNewElevation<=maxElevationDegrees) ?adzia?o by, ale lepiej u?y? metody Clamp
	auto Elevation = FMath::Clamp<float>(RawNewElevation, minElevationDegrees, maxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0)); // ustawiam nowa rotacje dla dzia?a
	
}


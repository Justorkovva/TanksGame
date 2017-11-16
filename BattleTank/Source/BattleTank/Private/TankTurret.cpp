// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "BattleTank.h"

UTankTurret::UTankTurret() { PrimaryComponentTick.bCanEverTick = false; }

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto YawChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewYaw = RelativeRotation.Yaw + YawChange;

	//auto NewYaw = FMath::Clamp<float>(RawNewYaw, minElevationDegrees, maxElevationDegrees); TODO sprawdzic, bo nie wiadomo czy po 180 idzie dalej
	SetRelativeRotation(FRotator(0, RawNewYaw, 0)); // ustawiam nowa rotacje dla dzia?a

		//UE_LOG(LogTemp, Warning, TEXT("Wchodze tu %f"), RawNewYaw);
	

}


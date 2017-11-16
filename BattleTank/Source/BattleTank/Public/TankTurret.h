// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

		UTankTurret();
	
public:
	void RotateTurret(float RelativeSpeed); //-1 left + 1 right

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 15;
	/*
	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevationDegrees = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevationDegrees = 40; //TODO use it
	*/

};

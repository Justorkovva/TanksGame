// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision")) // bedzie mozna ten komponent dodac do Tank_BP dzieki pierwszej deklaracji
//a druga ukrywa kategorie jesli nie chcielibysmy zeby byla mozliwosc ich edytowania

class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float minElevationDegrees = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
	float maxElevationDegrees = 40; //TODO use it

	
	
};

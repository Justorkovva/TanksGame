#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent)) // bedzie mozna ten komponent dodac do Tank_BP dzieki pierwszej deklaracji

class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	UTankBarrel();

public:
	void Elevate(float RelativeSpeed); //-1 downward max speed, +1 up movement

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float minElevationDegrees = 0;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float maxElevationDegrees = 40; 
};
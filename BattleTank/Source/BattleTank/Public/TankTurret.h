
#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	UTankTurret();
	
public:
	void RotateTurret(float RelativeSpeed); //-1 left + 1 right

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSecond = 15;
	/* moze trzeba bedzie uzyc, zeby prawo/lewo sie krecilo lepiej
	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevationDegrees = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevationDegrees = 40; //TODO use it
	*/
};
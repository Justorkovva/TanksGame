#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"


//Tank Track is used to set maximum driving force
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Input")
	void SetThrottle(float Throttle);


	UPROPERTY(EditDefaultsOnly)
		float TankMaxDrivingForce = 40000000; //1g acceleration

};

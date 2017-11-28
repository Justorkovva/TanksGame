#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"


//Tank Track is used to set maximum driving force
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UTankTrack();
	UFUNCTION(BlueprintCallable, Category="Input")
	void SetThrottle(float Throttle);

	void BeginPlay() override;
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);



	UPROPERTY(EditDefaultsOnly)
		float TankMaxDrivingForce = 40000000; //1g acceleration

};

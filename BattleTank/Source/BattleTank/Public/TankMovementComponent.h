#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading
};


class ATank;
class UTankTrack;

// movement of the tank
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveLeft(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveBackward(float Throw);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;	

	EFiringState FiringState = EFiringState::Reloading;
	EFiringState FiringState = EFiringState::Aiming;
	EFiringState FiringState = EFiringState::Locked;


};

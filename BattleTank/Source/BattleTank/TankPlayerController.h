// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

protected:
	void BeginPlay() override; 

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FindAimingComponent(UTankAimingComponent * AimCompRef);

public:
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;


	UPROPERTY(EditAnywhere)
		float CrosshairLocationX = 0.5; 

	UPROPERTY(EditAnywhere)
		float CrosshairLocationY = 0.33333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000; // obstawiam, ze jest w centymetrach

};

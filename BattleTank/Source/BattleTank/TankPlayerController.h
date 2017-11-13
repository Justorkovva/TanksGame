// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "BattleTank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

protected:
	void BeginPlay() override; 

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;


	UPROPERTY(EditAnywhere)
		float CrosshairLocationX = 0.5; 

	UPROPERTY(EditAnywhere)
		float CrosshairLocationY = 0.33333;


	
	
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();
	void AimAt(FVector HitLocation);

protected:
	virtual void BeginPlay() override;
	
public:	
	UPROPERTY(EditAnywhere) // mamy mozliwosc w Tank_BP dodac jaka tylko chcemy klase jako ProjectileBlueprint
		UClass* ProjectileBlueprint;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
		void Fire();

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UTankBarrel* Barrel = nullptr;
	UTankAimingComponent* AimingComponent = nullptr;
	

};

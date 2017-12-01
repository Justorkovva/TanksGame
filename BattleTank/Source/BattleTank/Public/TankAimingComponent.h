// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState: uint8 {
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

class UTankBarrel; //Forward Declaration
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable)
	void Initialise(UTankTurret* TankTurret, UTankBarrel* TankBarrel);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
		void Fire();

	EFiringState GetFiringState();

	UFUNCTION(BlueprintCallable)
	int32 GetProjectilesLeft();

private:
	UTankAimingComponent();
	UTankBarrel* Barrel = nullptr;
	void MoveBarrel(FVector AimDirection);
	bool IsMoving();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


	UTankTurret* Turret = nullptr;
	void MoveTurret(FVector AimDirection);

	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
	FVector AimDirection;

	UPROPERTY(EditAnywhere, Category = "Firing")
	int32 ProjectilesLeft = 3;
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

	

	UPROPERTY(EditAnywhere, Category = "Firing") //EditDefaultOnly oznaczaloby, ze nie mozna zmieniac dla osobnych tankow, tylko dla wszystkich na raz
		float LaunchSpeed = 4000;

	UPROPERTY(EditAnywhere) // mamy mozliwosc w Tank_BP dodac jaka tylko chcemy klase jako ProjectileBlueprint
		UClass* ProjectileBlueprint;
};
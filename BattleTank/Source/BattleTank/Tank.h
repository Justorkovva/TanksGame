#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();
	void AimAt(FVector HitLocation);

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere) // mamy mozliwosc w Tank_BP dodac jaka tylko chcemy klase jako ProjectileBlueprint
		UClass* ProjectileBlueprint;

	UFUNCTION(BlueprintCallable)
		void Fire();

	UPROPERTY(EditAnywhere, Category = "Firing") //EditDefaultOnly oznaczaloby, ze nie mozna zmieniac dla osobnych tankow, tylko dla wszystkich na raz
		float LaunchSpeed = 4000;

	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* MovementComponent = nullptr; //mozemy w BP wyciagnac z tego jego funkcje

	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* AimingComponent = nullptr;

private:
	UTankBarrel* Barrel = nullptr;
	

	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;

};
#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere) // mamy mozliwosc w Tank_BP dodac jaka tylko chcemy klase jako ProjectileBlueprint
		UClass* ProjectileBlueprint;

	UFUNCTION(BlueprintCallable)
		void Fire();

private:
	UTankBarrel* Barrel = nullptr;
	
	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = "Firing") //EditDefaultOnly oznaczaloby, ze nie mozna zmieniac dla osobnych tankow, tylko dla wszystkich na raz
		float LaunchSpeed = 4000;

};
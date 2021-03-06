#pragma once

#include "BattleTank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		bool CanFire = true;

	UPROPERTY(EditAnywhere)
		float Distance = 3000;

private:
	void SetPawn(APawn* InPawn) override;

	UFUNCTION()
		void OnPossessedTankDeath();
};

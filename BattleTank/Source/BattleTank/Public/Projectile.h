#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleTank.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"


UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	void LaunchProjectile(float Speed);
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* ProjectileLaunchBlast=nullptr;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ProjectileCollision=nullptr;

protected:
	virtual void BeginPlay() override;

private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;
};

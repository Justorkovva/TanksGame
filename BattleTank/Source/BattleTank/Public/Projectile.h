#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleTank.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"  
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
		UParticleSystemComponent* ProjectileImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ProjectileCollision=nullptr;

	UPROPERTY(VisibleAnywhere)
		URadialForceComponent* ExplosionForce = nullptr;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

protected:
	virtual void BeginPlay() override;

private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;
};

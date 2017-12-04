
#include "Projectile.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileCollision = CreateDefaultSubobject<UStaticMeshComponent>(FName("CollisionMesh"));
	SetRootComponent(ProjectileCollision);
	ProjectileCollision->SetNotifyRigidBodyCollision(true);
	ProjectileCollision->SetVisibility(false);

	ProjectileLaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	ProjectileLaunchBlast -> AttachTo(RootComponent);

	ProjectileMovement->bAutoActivate = false;



}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();	
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::LaunchProjectile(float Speed)
{
	//UE_LOG(LogTemp, Error, TEXT("FIRE!!!"));
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}
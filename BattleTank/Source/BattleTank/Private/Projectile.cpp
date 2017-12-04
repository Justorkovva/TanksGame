
#include "Projectile.h"
#include "Components/StaticMeshComponent.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileCollision = CreateDefaultSubobject<UStaticMeshComponent>(FName("CollisionMesh"));
	SetRootComponent(ProjectileCollision);
	ProjectileCollision->SetNotifyRigidBodyCollision(true);
	ProjectileCollision->SetVisibility(false);

	ProjectileLaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	ProjectileLaunchBlast -> AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ProjectileImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Explosion"));
	ProjectileImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ProjectileImpactBlast->bAutoActivate = false;
	ProjectileMovement->bAutoActivate = false;

	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
	ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();	
	ProjectileCollision->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	ProjectileLaunchBlast->Deactivate();
	ProjectileImpactBlast->Activate();
	ExplosionForce->FireImpulse();
	//wait
	//ExplosionForce->Deactivate();
}

void AProjectile::LaunchProjectile(float Speed)
{
	//UE_LOG(LogTemp, Error, TEXT("FIRE!!!"));
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}
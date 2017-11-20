
#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	if(CanFire)
	ControlledTank->Fire();
}




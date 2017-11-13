// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();


	if (!ControlledTank) {
		//UE_LOG(LogTemp, Warning, TEXT("AI Controller not possesing a tank"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing: %s"), *(ControlledTank->GetName()));
	}

if (!PlayerTank) { 
	//UE_LOG(LogTemp, Warning, TEXT("Player tank not found"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("Player tank found"));
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const 
{
	auto PlayerPawn=GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) 
	return nullptr;
	
return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {

		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}




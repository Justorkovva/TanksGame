// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possesing a tank"));
	}
	else {
		
	}


}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Tick Tock"));
}

void ATankPlayerController::AimTowardsCrosshair() { //celowanie 

	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) { // sprawdzam czy nie celuje w niebo
	//	UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const 
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairLocationX, ViewportSizeY * CrosshairLocationY);
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{	
			UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
		
	}


	//OutHitLocation = FVector(1.0);

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {

	FVector CameraWorldLocation;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *WorldDirection.ToString());
	
	return true;
}



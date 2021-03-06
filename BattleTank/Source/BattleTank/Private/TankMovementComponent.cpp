// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);

	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendMoveRight(RightThrow);

	//UE_LOG(LogTemp, Warning, TEXT("%s is vectoring to  %s"), *TankName, *MoveVelocityString);
}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!ensure(LeftTrackToSet) || !ensure(RightTrackToSet)) { return; }
	LeftTrack=LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendMoveLeft(float Throw)
{
	LeftTrack->SetThrottle(-1.5*Throw);
	RightTrack->SetThrottle(1.5 *Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	LeftTrack->SetThrottle(1.5* Throw);
	RightTrack->SetThrottle(-1.5 * Throw);
}


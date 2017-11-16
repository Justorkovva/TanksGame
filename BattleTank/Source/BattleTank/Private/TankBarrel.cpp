// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "BattleTank.h"


UTankBarrel::UTankBarrel()
{
	PrimaryComponentTick.bCanEverTick = false;	
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto Time = GetWorld()->GetTimeSeconds();
}


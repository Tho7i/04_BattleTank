// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Begin play for player controller"));
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank :("));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Posessing: %s"), *ControlledTank->GetName())
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
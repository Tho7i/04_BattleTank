// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AIControlledTank = GetAIPossesedTank();
	auto FirstPlayerTank = GetPlayerTank();

	if (!FirstPlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find a player tank!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI finds this player tank: %s"), *FirstPlayerTank->GetName())
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		auto PlayerTankLocation = GetPlayerTank()->GetActorLocation();
		GetAIPossesedTank()->AimAt(PlayerTankLocation);
	}
}



ATank* ATankAIController::GetAIPossesedTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerTank);
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//TODO move towards player
		auto PlayerTankLocation = PlayerTank->GetActorLocation();
		AITank->AimAt(PlayerTankLocation);

		AITank->Fire(); //TODO limit fire rate
	}
}
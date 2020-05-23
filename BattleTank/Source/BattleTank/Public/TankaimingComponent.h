// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankaimingComponent.generated.h"

// Forward declaration
class UTankBarrel;


//Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankaimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankaimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

protected:

public:	
	void AimAt(FVector HitLocation, float LaunchSpeed);


private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
};

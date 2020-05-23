// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "TankTurret.h"



void UTankTurret::Rotate(float RotationRelativeSpeed)
{
	RotationRelativeSpeed = FMath::Clamp<float>(RotationRelativeSpeed, -1, +1);

	auto RotationChange = RotationRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}
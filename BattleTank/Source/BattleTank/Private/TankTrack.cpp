// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"



void UTankTrack::SetThrottle(float Throttle)
{
	//TODO clamp throttle
	auto ForceApplied = GetForwardVector() * Throttle * TankMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto Root = Cast<UPrimitiveComponent> (GetOwner()->GetRootComponent());

	Root->AddForceAtLocation(ForceApplied, ForceLocation);
}
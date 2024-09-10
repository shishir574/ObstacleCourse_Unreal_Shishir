// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	//UE_LOG(LogTemp, Warning, TEXT("LOG MESSAGE"));
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();

	if (ShouldPlatformReverse())
	{
		PlatformVelocity = -PlatformVelocity;
	}
	
	CurrentLocation += PlatformVelocity * DeltaTime;
	SetActorLocation(CurrentLocation);
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotateVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReverse() const
{
	return (GetDistanceMoved(StartLocation) > DistanceLimits);
}
float AMovingPlatform::GetDistanceMoved(FVector ToLocation) const
{
	return FVector::Dist(GetActorLocation(), ToLocation);
}


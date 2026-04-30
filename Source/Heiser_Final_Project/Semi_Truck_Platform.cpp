// Fill out your copyright notice in the Description page of Project Settings.


#include "Semi_Truck_Platform.h"

// Sets default values
ASemi_Truck_Platform::ASemi_Truck_Platform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASemi_Truck_Platform::BeginPlay()
{
	Super::BeginPlay();
	
	isAscending = true;
}

// Called every frame
void ASemi_Truck_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Move truck upwards every frame until it reaches the given target height
	if (isAscending)
	{
		SetActorLocation(GetActorLocation() + GetActorUpVector() * moveSpeed * DeltaTime);
		
		if (GetActorLocation().Z > targetHeight) isAscending = false;
	}
}
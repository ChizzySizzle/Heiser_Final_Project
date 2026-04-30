// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Semi_Truck_Platform.generated.h"

UCLASS()
class HEISER_FINAL_PROJECT_API ASemi_Truck_Platform : public AActor
{
	GENERATED_BODY()
	
public:	
	bool isAscending;
	
	// These are set in blueprints before instantiation
	UPROPERTY(BlueprintReadWrite)
	float targetHeight;
	UPROPERTY(BlueprintReadWrite)
	float moveSpeed;
	
	// Sets default values for this actor's properties
	ASemi_Truck_Platform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

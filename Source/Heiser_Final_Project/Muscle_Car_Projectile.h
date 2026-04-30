// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Heiser_Final_ProjectCharacter.h"
#include "GameFramework/Actor.h"
#include "Muscle_Car_Projectile.generated.h"

UCLASS()
class HEISER_FINAL_PROJECT_API AMuscle_Car_Projectile : public AActor
{
	GENERATED_BODY()
	
	bool beingCarried = false;
	
public:	
	// Sets default values for this actor's properties
	AMuscle_Car_Projectile();
	
	UFUNCTION(BlueprintCallable)
	void FireProjectile();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AHeiser_Final_ProjectCharacter *ownerCharacter;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent *staticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

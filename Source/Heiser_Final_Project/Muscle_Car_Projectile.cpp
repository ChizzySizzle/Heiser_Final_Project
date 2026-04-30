// Fill out your copyright notice in the Description page of Project Settings.


#include "Muscle_Car_Projectile.h"

#include "Misc/MapErrors.h"

// Sets default values
AMuscle_Car_Projectile::AMuscle_Car_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMuscle_Car_Projectile::BeginPlay()
{
	Super::BeginPlay();
	
	// Get a reference to the static mesh component
	staticMesh = Cast<UStaticMeshComponent>(
		this->GetComponentByClass(UStaticMeshComponent::StaticClass())
	);;
	
	// Is carried from instantiation
	beingCarried = true;
}

// Called every frame
void AMuscle_Car_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Lerp the muscle car to the right side of the player, using the rigidbody to give it more realistic movement
	if (ownerCharacter != nullptr && beingCarried)
	{
		if (staticMesh && staticMesh->IsSimulatingPhysics())
		{
			// Get the target location and the current location then find the difference between the two
			FVector Target = ownerCharacter->GetActorLocation() + ownerCharacter->GetActorRightVector() * 200 + ownerCharacter->GetActorUpVector() * 50;
			FVector Current = staticMesh->GetComponentLocation();
			FVector Delta = Target - Current;
			
			// Vars that change how strong the pull towards the target is
			float Mass = staticMesh->GetMass();
			float Strength = 200.0f;
			
			FVector DriveForce = Delta * Strength * Mass;

			staticMesh->AddForce(DriveForce);
			
			// Use the same local rotation as the player
			FRotator TargetRot = ownerCharacter->GetActorRotation() + FRotator(0, -90, 0);
			FRotator CurrentRot = staticMesh->GetComponentRotation();
			FRotator NewRot = FMath::RInterpTo(CurrentRot, TargetRot, DeltaTime, 100.0f);
			staticMesh->SetWorldRotation(NewRot);
		}
	}
}

void AMuscle_Car_Projectile::FireProjectile()
{
	// Throw the car
	beingCarried = false;
	staticMesh->SetEnableGravity(true);
	staticMesh->SetLinearDamping(0.2f);
	staticMesh->AddImpulse(ownerCharacter->GetControlRotation().Vector() * 2000000);
}
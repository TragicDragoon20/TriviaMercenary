// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "DrawDebugHelpers.h"
#include "../Movement/PlayerMovement.h"
#include "Camera/CameraComponent.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AWeapon::TraceForward(OUT FHitResult& hit, ECollisionChannel channel, bool drawDebugLine)
{
	UCameraComponent* camera = Cast<APlayerMovement>(GetOwner())->GetCameraComponent();

	// Stop if we can't get the camera
	if (camera == nullptr)
		return false;

	// Use this actor's location for start vector
	FVector start = camera->GetComponentLocation();

	// Get forward vector from first person camera component
	FVector direction = camera->GetForwardVector();

	// Calculate end point
	FVector end = start + (direction * maxFireDistance);

	FCollisionQueryParams collisionParams;

	bool isHit = GetWorld()->LineTraceSingleByChannel(hit, start, end, channel, collisionParams);

	// Draw debug information
	if (drawDebugLine)
	{
		const float lifetime = 2.0f;
		DrawDebugLine(GetWorld(), start, end, FColor::Orange, false, lifetime);

		if (isHit)
		{
			DrawDebugBox(GetWorld(), hit.ImpactPoint, FVector(5, 5, 5), FColor::Emerald, false, lifetime);
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Emerald, FString::Printf(TEXT("Forward Trace Hit. Actor Name: %s"), *hit.GetActor()->GetName()));
		}
	}

	return isHit;
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::PrimaryFire()
{
	timeOfLastFire = GetWorld()->GetTimeSeconds();
}

void AWeapon::SecondaryFire()
{

}

void AWeapon::PrimaryFirePressed()
{
	switch (firingMode)
	{
	case EFiringMode::FullyAutomatic:
		GetWorldTimerManager().SetTimer(autoFireTimerHandle, this, &AWeapon::PrimaryFire, autoFireInterval, true, FMath::Clamp(autoFireInterval - (GetWorld()->GetTimeSeconds() - timeOfLastFire), 0.0f, autoFireInterval));
		break;
	case EFiringMode::SemiAutomatic:
		PrimaryFire();
		break;
	default:
		break;
	}
}

void AWeapon::PrimaryFireReleased()
{
	GetWorldTimerManager().ClearTimer(autoFireTimerHandle);
}

void AWeapon::SecondaryFirePressed()
{

}

void AWeapon::SecondaryFireReleased()
{

}

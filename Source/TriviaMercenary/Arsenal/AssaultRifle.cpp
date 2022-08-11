// Fill out your copyright notice in the Description page of Project Settings.

#include "AssaultRifle.h"
#include "../Movement/PlayerMovement.h"
#include "Camera/CameraComponent.h"

// Sets default values
AAssaultRifle::AAssaultRifle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetMagazineAmmo(startingAmmoInMagazine);
}

void AAssaultRifle::PrimaryFire()
{
	if (magazineAmmo <= 0)
		return;

	AWeapon::PrimaryFire();

	SetMagazineAmmo(magazineAmmo - 1);

	FHitResult hit;
	if (TraceForward(hit, ECC_Visibility, showTraceDebugInfo))
	{
		// Check if what we've hit is an actor
		if (AActor* target = hit.GetActor())
		{
			// Calculate shot direction
			// todo: probably use start location as a variable from TraceForward instead of getting it via GetActorLocation()?
			FVector inDir = hit.ImpactPoint - GetActorLocation();
			inDir.Normalize();

			// Apply damage at point of impact
			target->TakeDamage
			(
				baseDamage,
				FPointDamageEvent(baseDamage, hit, inDir, baseDamageType),
				GetOwner()->GetInstigatorController(),
				this
			);
		}
	}
}

void AAssaultRifle::SecondaryFire()
{
	AWeapon::SecondaryFire();

	if (toggleADS && isADS)
		StopADS();
	else
		StartADS();
}

void AAssaultRifle::Reload()
{
	SetMagazineAmmo(magazineSize);
}

int AAssaultRifle::SetMagazineAmmo(int Value)
{
	float newAmmo = FMath::Clamp(Value, 0.0f, magazineSize);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("New ammo: %f"), newAmmo));
	}
	return magazineAmmo = newAmmo;
}

void AAssaultRifle::SecondaryFireReleased()
{
	Super::SecondaryFireReleased();

	if (!toggleADS)
		StopADS();
}

void AAssaultRifle::StartADS()
{
	if (camera != nullptr)
	{
		isADS = true;
		camera->SetFieldOfView(adsFOV);
	}
}

void AAssaultRifle::StopADS()
{
	if (camera != nullptr)
	{
		isADS = false;
		camera->SetFieldOfView(player->startingFOV);
	}
}

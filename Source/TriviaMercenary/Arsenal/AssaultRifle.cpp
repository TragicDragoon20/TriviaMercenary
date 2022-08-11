// Fill out your copyright notice in the Description page of Project Settings.

#include "AssaultRifle.h"

void AAssaultRifle::PrimaryFire()
{
	AWeapon::PrimaryFire();

	FHitResult hit;
	if (TraceForward(hit, ECC_Visibility, showTraceDebugInfo))
	{
		AActor* target = hit.GetActor();
		if (IsValid(target))
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
}
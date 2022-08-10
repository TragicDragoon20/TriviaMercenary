// Fill out your copyright notice in the Description page of Project Settings.

#include "AssaultRifle.h"
#include "../Movement/PlayerMovement.h"
#include "Camera/CameraComponent.h"

void AAssaultRifle::PrimaryFire()
{
	AWeapon::PrimaryFire();

	FHitResult hit;
	FVector start = GetActorLocation();
	// Get forward vector from first person camera component
	FVector direction = Cast<APlayerMovement>(GetOwner())->GetCameraComponent()->GetForwardVector();
	FVector end = start + (direction * maxFireDistance);
	FCollisionQueryParams collisionParams;

	DrawDebugLine(GetWorld(), start, end, FColor::Green, true);

	bool isHit = GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility, collisionParams);

	if (isHit)
	{
		if (hit.bBlockingHit)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Emerald, FString::Printf(TEXT("we hit something lads: %s"), *hit.GetActor()->GetName()));
		}
	}
}

void AAssaultRifle::SecondaryFire()
{
	AWeapon::SecondaryFire();
}
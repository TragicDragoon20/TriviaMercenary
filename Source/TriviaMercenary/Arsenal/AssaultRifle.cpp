// Fill out your copyright notice in the Description page of Project Settings.

#include "AssaultRifle.h"

void AAssaultRifle::PrimaryFire()
{
	AWeapon::PrimaryFire();

	FHitResult hit;
	TraceForward(hit, ECC_Visibility, showTraceDebugInfo);
}

void AAssaultRifle::SecondaryFire()
{
	AWeapon::SecondaryFire();
}
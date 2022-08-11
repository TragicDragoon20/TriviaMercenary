// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "AssaultRifle.generated.h"

UCLASS()
class TRIVIAMERCENARY_API AAssaultRifle : public AWeapon
{
	GENERATED_BODY()
	
public:
	virtual void PrimaryFire() override;
	virtual void SecondaryFire() override;
};

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
	// Sets default values for this actor's properties
	AAssaultRifle();

	virtual void PrimaryFire() override;
	virtual void SecondaryFire() override;
	virtual void Reload();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammo")
	int magazineAmmo = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int magazineSize = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int startingAmmoInMagazine = 32;

protected:
	virtual int SetMagazineAmmo(int Value);
};

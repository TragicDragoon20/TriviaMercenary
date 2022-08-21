// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "AssaultRifle.generated.h"

// Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetMagazineAmmo, int, NewAmmo);

UCLASS()
class TRIVIAMERCENARY_API AAssaultRifle : public AWeapon
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AAssaultRifle();

public:
	UPROPERTY(BlueprintAssignable, Category = "Ammo")
	FSetMagazineAmmo OnSetMagazineAmmo;

public:
	virtual void PrimaryFire() override;
	virtual void SecondaryFire() override;
	virtual void SecondaryFireReleased() override;
	virtual void Reload();
	virtual void StartADS();
	virtual void StopADS();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ammo")
	int magazineAmmo = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int magazineSize = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int startingAmmoInMagazine = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aim Down Sights")
	float adsFOV = 70.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Aim Down Sights")
	bool isADS = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aim Down Sights")
	bool toggleADS = false;

protected:
	virtual int SetMagazineAmmo(int Value);
};

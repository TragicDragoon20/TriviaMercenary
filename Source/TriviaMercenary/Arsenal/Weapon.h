// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EFiringMode : uint8
{
	FullyAutomatic	UMETA(DisplayName = "Fully Automatic"),
	SemiAutomatic	UMETA(DisplayName = "Semi Automatic"),
};

UCLASS()
class TRIVIAMERCENARY_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PrimaryFire();
	virtual void SecondaryFire();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	EFiringMode firingMode;

};

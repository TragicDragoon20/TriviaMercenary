// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class APlayerMovement;

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
	virtual bool TraceForward(OUT FHitResult& hit, ECollisionChannel channel, bool drawDebugLine = false);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PrimaryFire();
	virtual void SecondaryFire();
	virtual void PrimaryFirePressed();
	virtual void PrimaryFireReleased();
	virtual void SecondaryFirePressed();
	virtual void SecondaryFireReleased();

public:
	// Selected firing mode (automatic, semi-automatic, etc.)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	EFiringMode firingMode;

	// Fully automatic firing mode firing interval
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float autoFireInterval = 0.5f;

	// Trace distance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float maxFireDistance = 10000.0f;

	// Base damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int baseDamage = 5;

	// Base damage type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<UDamageType> baseDamageType;

	// Show debug info
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Debug")
	bool showTraceDebugInfo = false;

protected:
	FTimerHandle autoFireTimerHandle;
	float timeOfLastFire = 0.0f;
};
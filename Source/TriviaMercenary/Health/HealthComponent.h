// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

// Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetHealthDelegate, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealDelegate, float, HealAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathDelegate);

UCLASS(ClassGroup=(Health), meta=(BlueprintSpawnableComponent))
class TRIVIAMERCENARY_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	// Delegates
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FSetHealthDelegate OnSetHealth;
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FHealDelegate OnHeal;
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FDeathDelegate OnDeath;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float health = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	bool isDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float startingHealth = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float maxHealth = 100;

	UFUNCTION()
	virtual void SetHealth(float Value);

	virtual void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	virtual void Heal(float Amount);

	virtual void Death();
};

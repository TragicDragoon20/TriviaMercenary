// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRIVIAMERCENARY_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

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
	virtual void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	virtual void SetHealth(float Value);
	virtual void Death();
};

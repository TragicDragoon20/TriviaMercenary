// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyHealthComponent.h"
#include "AnswerEnemyHealthComponent.generated.h"

UCLASS(ClassGroup = (Health), meta = (BlueprintSpawnableComponent))
class TRIVIAMERCENARY_API UAnswerEnemyHealthComponent : public UEnemyHealthComponent
{
	GENERATED_BODY()
	
protected:
	virtual void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser) override;
	virtual void SetHealth(float Value) override;
	virtual void Death() override;
};

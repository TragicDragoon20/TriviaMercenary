// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHealthComponent.h"

void UEnemyHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCause)
{
	UHealthComponent::TakeDamage(DamagedActor, Damage, DamageType, InstigatedBy, DamageCause);
}

void UEnemyHealthComponent::SetHealth(float Value)
{
	UHealthComponent::SetHealth(Value);
}

void UEnemyHealthComponent::Death()
{
	UHealthComponent::Death();
}
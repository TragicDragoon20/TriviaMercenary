// Fill out your copyright notice in the Description page of Project Settings.


#include "AnswerEnemyHealthComponent.h"

void UAnswerEnemyHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCause)
{
	UEnemyHealthComponent::TakeDamage(DamagedActor, Damage, DamageType, InstigatedBy, DamageCause);
}

void UAnswerEnemyHealthComponent::SetHealth(float Value)
{
	UEnemyHealthComponent::SetHealth(Value);
}

void UAnswerEnemyHealthComponent::Death()
{
	UEnemyHealthComponent::Death();
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthComponent.h"

void UPlayerHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCause)
{
	UHealthComponent::TakeDamage(DamagedActor, Damage, DamageType, InstigatedBy, DamageCause);
}

void UPlayerHealthComponent::SetHealth(float Value)
{
	UHealthComponent::SetHealth(Value);
}

void UPlayerHealthComponent::Death()
{
	UHealthComponent::Death();
}
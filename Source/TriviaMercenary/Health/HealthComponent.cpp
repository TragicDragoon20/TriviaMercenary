// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	SetHealth(startingHealth);

	if (AActor* owner = GetOwner())
	{
		owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
	
}


void UHealthComponent::SetHealth(float Value)
{
	health = FMath::Clamp(Value, 0.0f, maxHealth);
	OnSetHealth.Broadcast(health);

	if (health <= 0)
	{
		Death();
	}
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (isDead || Damage <= 0)
		return;

	SetHealth(health - Damage);
}

void UHealthComponent::Heal(float Amount) 
{
	if (isDead || Amount <= 0)
		return;

	OnHeal.Broadcast(Amount);
	SetHealth(health + Amount);

}

void UHealthComponent::Death()
{
	if (isDead)
		return;

	OnDeath.Broadcast();
	isDead = true;
}
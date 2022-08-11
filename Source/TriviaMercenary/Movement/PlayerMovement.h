// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerMovement.generated.h"

class UCameraComponent;
class AWeapon;
class AAssaultRifle;

UCLASS()
class TRIVIAMERCENARY_API APlayerMovement : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerMovement();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UCameraComponent* GetCameraComponent();

	UPROPERTY(VisibleAnywhere, Category = "Component")
	float startingFOV;

private:
	// Movement
	void MoveForward(float value);
	void MoveRight(float value);
	void Crouch();
	void UnCrouch();

	// Weapon
	void OnPrimaryFirePressed();
	void OnPrimaryFireReleased();
	void OnSecondaryFirePressed();
	void OnSecondaryFireReleased();
	void OnReloadPressed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* cameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AWeapon> weapon;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	AWeapon* currentWeapon;
};

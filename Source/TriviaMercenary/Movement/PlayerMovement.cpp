// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovement.h"
#include "Camera/CameraComponent.h"
#include "../Arsenal/Weapon.h"
#include "Engine/World.h"

// Sets default values
APlayerMovement::APlayerMovement()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APlayerMovement::BeginPlay()
{
	Super::BeginPlay();	

	currentWeapon = Cast<AWeapon>(GetWorld()->SpawnActor(weapon));
	//currentWeapon = Cast<AWeapon>(GetWorld()->SpawnActor(weapon, GetActorLocation(), GetActorRotation()));

	currentWeapon->SetActorLocation(GetActorLocation());
	currentWeapon->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
}

// Called every frame
void APlayerMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind movement input
	PlayerInputComponent->BindAxis("Move Forward", this, &APlayerMovement::MoveForward);
	PlayerInputComponent->BindAxis("Move Right", this, &APlayerMovement::MoveRight);
	PlayerInputComponent->BindAxis("Look Up Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn Right Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &APlayerMovement::Crouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &APlayerMovement::UnCrouch);

	// Bind weapon input
	PlayerInputComponent->BindAction("Primary Fire", IE_Pressed, this, &APlayerMovement::OnPrimaryFirePressed);
	PlayerInputComponent->BindAction("Secondary Fire", IE_Pressed, this, &APlayerMovement::OnSecondaryFirePressed);
}

void APlayerMovement::Crouch()
{
	this->ACharacter::Crouch();
}

void APlayerMovement::UnCrouch()
{
	this->ACharacter::UnCrouch();
}

void APlayerMovement::MoveForward(float value)
{
	FVector direction = FRotationMatrix(this->GetActorForwardVector().Rotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, value * 10);
}

void APlayerMovement::MoveRight(float value)
{
	FVector direction = FRotationMatrix(this->GetActorRightVector().Rotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, value * 10);
}

void APlayerMovement::OnPrimaryFirePressed()
{
	currentWeapon->PrimaryFire();
}

void APlayerMovement::OnSecondaryFirePressed()
{
	currentWeapon->SecondaryFire();
}


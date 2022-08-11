// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovement.h"
#include "Camera/CameraComponent.h"
#include "../Arsenal/Weapon.h"
#include "../Arsenal/AssaultRifle.h"
#include "Engine/World.h"

// Sets default values
APlayerMovement::APlayerMovement()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->SetupAttachment(RootComponent);
	startingFOV = cameraComponent->FieldOfView;
}

// Called when the game starts or when spawned
void APlayerMovement::BeginPlay()
{
	Super::BeginPlay();	

	// Spawn starting weapon at player then attach
	currentWeapon = GetWorld()->SpawnActor<AWeapon>(weapon, GetActorLocation(), FRotator::ZeroRotator);
	currentWeapon->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
	currentWeapon->SetOwner(this);
	currentWeapon->OnPickup();
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
	PlayerInputComponent->BindAction("Primary Fire", IE_Released, this, &APlayerMovement::OnPrimaryFireReleased);
	PlayerInputComponent->BindAction("Secondary Fire", IE_Pressed, this, &APlayerMovement::OnSecondaryFirePressed);
	PlayerInputComponent->BindAction("Secondary Fire", IE_Released, this, &APlayerMovement::OnSecondaryFireReleased);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &APlayerMovement::OnReloadPressed);
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
	if (!IsValid(currentWeapon))
		return;

	currentWeapon->PrimaryFirePressed();
}

void APlayerMovement::OnPrimaryFireReleased()
{
	if (!IsValid(currentWeapon))
		return;

	currentWeapon->PrimaryFireReleased();

}

void APlayerMovement::OnSecondaryFirePressed()
{
	if (!IsValid(currentWeapon))
		return;

	currentWeapon->SecondaryFirePressed();
}

void APlayerMovement::OnSecondaryFireReleased()
{
	if (!IsValid(currentWeapon))
		return;

	currentWeapon->SecondaryFireReleased();
}

void APlayerMovement::OnReloadPressed()
{
	if (!IsValid(currentWeapon))
		return;

	if (AAssaultRifle* rifle = Cast<AAssaultRifle>(currentWeapon))
		rifle->Reload();
}

UCameraComponent* APlayerMovement::GetCameraComponent()
{
	return cameraComponent;
}


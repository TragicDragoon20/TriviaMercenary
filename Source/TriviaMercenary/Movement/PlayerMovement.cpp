// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovement.h"
#include "Camera/CameraComponent.h"

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

	PlayerInputComponent->BindAxis("Move Forward", this, &APlayerMovement::MoveForward);
	PlayerInputComponent->BindAxis("Move Right", this, &APlayerMovement::MoveRight);
	PlayerInputComponent->BindAxis("Look Up Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn Right Mouse", this, &APawn::AddControllerYawInput);



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


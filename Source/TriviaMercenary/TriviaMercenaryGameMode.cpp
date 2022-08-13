// Copyright Epic Games, Inc. All Rights Reserved.

#include "TriviaMercenaryGameMode.h"
#include "TriviaMercenaryCharacter.h"
#include "UObject/ConstructorHelpers.h"
//#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TMGameState.h"

ATriviaMercenaryGameMode::ATriviaMercenaryGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	GameStateClass = ATMGameState::StaticClass();

	currentFloorIndex = 0;

}

void ATriviaMercenaryGameMode::StartPlay()
{
	// ..

	Super::StartPlay();
}

void ATriviaMercenaryGameMode::BeginPlay()
{
	Super::BeginPlay();

	controller = GetWorld()->GetFirstPlayerController();

	FInputModeGameOnly inputMode;
	controller->SetInputMode(inputMode);
	controller->bShowMouseCursor = false;

	currentState = EGameState::PreRun;
}

void ATriviaMercenaryGameMode::NewRun()
{
	currentState = EGameState::PreFloor;
}

void ATriviaMercenaryGameMode::NextFloor()
{
	currentState = EGameState::PreFloor;
}

void ATriviaMercenaryGameMode::FloorComplete()
{
	currentState = EGameState::PostFloor;
}

void ATriviaMercenaryGameMode::RoundComplete()
{

}

void ATriviaMercenaryGameMode::WaveComplete()
{

}

void ATriviaMercenaryGameMode::RunOver()
{
	currentState = EGameState::PostRun;
}

void ATriviaMercenaryGameMode::EndGame()
{

}
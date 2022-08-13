// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TriviaMercenaryGameMode.generated.h"

enum class EGameState : uint8
{
	PreRun,
	PreFloor,
	MidFloor,
	PostFloor,
	PostRun,
};

UCLASS(minimalapi)
class ATriviaMercenaryGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATriviaMercenaryGameMode();

	virtual void StartPlay() override;

	void NewRun();
	void NextFloor();

	void FloorComplete();
	void RoundComplete();
	void WaveComplete();

	void RunOver();

	void EndGame();

protected:
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Mode")
	//TSubclassOf<UUserWidget> defaultFloorCompleteWidget;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Mode")
	//TSubclassOf<UUserWidget> floorCompleteWidget;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Mode")
	//TSubclassOf<UUserWidget> defaultRunOverWidget;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Mode")
	//TSubclassOf<UUserWidget> runOverWidget;

	APlayerController* controller;
	int32 currentFloorIndex = 0;
	EGameState currentState = EGameState::PreRun;

private:
	void BeginPlay() override;
};




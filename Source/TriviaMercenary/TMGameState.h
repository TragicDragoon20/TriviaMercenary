// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TMGameState.generated.h"

/**
 * 
 */
UCLASS()
class TRIVIAMERCENARY_API ATMGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ATMGameState();
	virtual ~ATMGameState() = default;
};

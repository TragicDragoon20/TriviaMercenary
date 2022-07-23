// Copyright Epic Games, Inc. All Rights Reserved.

#include "TriviaMercenaryGameMode.h"
#include "TriviaMercenaryCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATriviaMercenaryGameMode::ATriviaMercenaryGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

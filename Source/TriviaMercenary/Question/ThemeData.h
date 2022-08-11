// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ThemeData.generated.h"

UCLASS()
class TRIVIAMERCENARY_API UThemeData : public UDataAsset
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Theme;
};

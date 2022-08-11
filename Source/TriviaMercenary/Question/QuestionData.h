// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestionData.generated.h"

class UThemeData;
class UAnswerData;

UCLASS()
class TRIVIAMERCENARY_API UQuestionData : public UDataAsset
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Question;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UThemeData* Theme;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UAnswerData*> Answers;
};

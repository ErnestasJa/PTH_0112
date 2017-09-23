// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PartehGameInstance.generated.h"

UENUM(BlueprintType)
enum class ELevelOutcomeEnum : uint8
{
	LO_Win UMETA(DisplayName = "Win"),
	LO_Lose UMETA(DisplayName = "Lose"),
};

/**
 * 
 */
UCLASS()
class PARTEH_API UPartehGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cross level data")
	ELevelOutcomeEnum LevelOutcome;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ScoreboardPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PARTEH_API AScoreboardPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	// Override BeginPlay()
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> wMainMenu;


protected:
	// Variable to hold the widget After Creating it.
	UUserWidget* MyMainMenu;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "CrappyFlapController.generated.h"

/**
 * This is custom flappy crap controller class.
 */
UCLASS(config = Game, BlueprintType, Blueprintable, meta = (ShortTooltip = "A flapper player Controller is an actor responsible for controlling a Pawn used by the player."))
class PARTEH_API ACrappyFlapController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetupInputComponent() override;
	void OnFlapStart();
	void OnFlapEnd();
};

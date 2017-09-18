// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CrappyFlapGameMode.generated.h"

/**
 * 
 */
UCLASS(config = Game, notplaceable, BlueprintType, Blueprintable, Transient, hideCategories = (Info, Rendering, MovementReplication, Replication, Actor), meta = (ShortTooltip = "Game Mode Base defines the game being played, its rules, scoring, and other facets of the game type."))
class PARTEH_API ACrappyFlapGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACrappyFlapGameMode(const FObjectInitializer& ObjectInitializer);
	
	
};

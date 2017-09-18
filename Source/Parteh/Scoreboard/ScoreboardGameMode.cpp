// Fill out your copyright notice in the Description page of Project Settings.

#include "ScoreboardGameMode.h"
#include "ScoreboardPlayerController.h"
#include "ConstructorHelpers.h"
#include "UObject/UObjectGlobals.h"
#include "EngineUtils.h"

AScoreboardGameMode::AScoreboardGameMode() {
	static ConstructorHelpers::FObjectFinder<UBlueprint> Blueprint(TEXT("Blueprint'/Game/Scoreboard/ScoreboardPlayerControllerBP.ScoreboardPlayerControllerBP'"));
	if (Blueprint.Object) {
		PlayerControllerClass = (UClass*)Blueprint.Object->GeneratedClass;
	}
	else {
		PlayerControllerClass = AScoreboardPlayerController::StaticClass();
	}
}


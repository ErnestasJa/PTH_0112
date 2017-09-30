// Fill out your copyright notice in the Description page of Project Settings.

#include "CrappyFlapGameMode.h"
#include "CrappyFlapCharacter.h"
#include "CrappyFlapController.h"
#include "ConstructorHelpers.h"
#include "UObject/UObjectGlobals.h"
#include "EngineUtils.h"

ACrappyFlapGameMode::ACrappyFlapGameMode(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.DoNotCreateDefaultSubobject(TEXT("Sprite"))),
	TimeUntilStart(3)
{
}

void ACrappyFlapGameMode::BeginPlay() {
	Super::BeginPlay();

	FTimerHandle unusedHandle;
	GetWorldTimerManager().SetTimer(unusedHandle, this, &ACrappyFlapGameMode::GameStartTimer, 3, false);
}

void ACrappyFlapGameMode::GameStartTimer() {
	if (TimeUntilStart > 0) {
		TimeUntilStart -= 1;
		FTimerHandle unusedHandle;
		GetWorldTimerManager().SetTimer(unusedHandle, this, &ACrappyFlapGameMode::GameStartTimer, 1, false);
	}
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "CrappyFlapGameMode.h"
#include "CrappyFlapCharacter.h"
#include "CrappyFlapController.h"
#include "ConstructorHelpers.h"
#include "UObject/UObjectGlobals.h"
#include "EngineUtils.h"

ACrappyFlapGameMode::ACrappyFlapGameMode(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.DoNotCreateDefaultSubobject(TEXT("Sprite")))
{

}



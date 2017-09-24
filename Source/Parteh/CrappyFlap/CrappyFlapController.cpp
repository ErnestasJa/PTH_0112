// Fill out your copyright notice in the Description page of Project Settings.

#include "CrappyFlapController.h"
#include "CrappyFlapCharacter.h"
#include "Engine.h"


void ACrappyFlapController::SetupInputComponent()
{
	Super::SetupInputComponent();

	this->InputComponent->BindAction("Flap", EInputEvent::IE_Pressed, this, &ACrappyFlapController::OnFlapStart);
	this->InputComponent->BindAction("Flap", EInputEvent::IE_Released, this, &ACrappyFlapController::OnFlapEnd);
}


void ACrappyFlapController::OnFlapStart()
{
	ACrappyFlapCharacter* character = Cast<ACrappyFlapCharacter>(this->GetCharacter());
	if (character)
	{
		character->Jump();
		character->ResetJumpState();
	}
}

void ACrappyFlapController::OnFlapEnd()
{
	ACrappyFlapCharacter* character = Cast<ACrappyFlapCharacter>(this->GetCharacter());
	if (character)
	{
		character->StopJumping();
	}
}
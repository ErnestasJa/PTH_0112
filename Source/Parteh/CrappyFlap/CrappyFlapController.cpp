// Fill out your copyright notice in the Description page of Project Settings.

#include "CrappyFlapController.h"
#include "CrappyFlapCharacter.h"
#include "Engine.h"


void ACrappyFlapController::SetupInputComponent()
{
	Super::SetupInputComponent();

	this->PlayerInputComponent = this->InputComponent;

	this->PlayerInputComponent->Activate();

	this->InputComponent->BindAction("Flap", EInputEvent::IE_Pressed, this, &ACrappyFlapController::OnFlapStart);
	this->InputComponent->BindAction("Flap", EInputEvent::IE_Released, this, &ACrappyFlapController::OnFlapEnd);

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Trying to flap"));
}


void ACrappyFlapController::OnFlapStart()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Flap"));
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

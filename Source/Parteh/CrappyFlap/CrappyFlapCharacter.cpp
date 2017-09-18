// Fill out your copyright notice in the Description page of Project Settings.

#include "CrappyFlapCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperTileMap.h"
#include "PaperTileSet.h"
#include "PaperTileMapComponent.h"
#include "Engine.h"

class UPaperTileMapComponent;

FName ACrappyFlapCharacter::SpriteComponentName(TEXT("Sprite0"));

ACrappyFlapCharacter::ACrappyFlapCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	// Try to create the sprite component
	Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(ACrappyFlapCharacter::SpriteComponentName);
	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->bGenerateOverlapEvents = false;

		GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ACrappyFlapCharacter::OnHit);
	}

	Speed = 10;
}

void ACrappyFlapCharacter::PostInitializeComponents() {
	Super::PostInitializeComponents();
	this->JumpMaxCount = 999;
	auto comp = this->GetCharacterMovement();
}

void ACrappyFlapCharacter::Tick(float deltaSeconds) {
	Super::Tick(deltaSeconds);

	this->AddMovementInput(FVector(Speed * deltaSeconds, 0, 0));
}
#include "DrawDebugHelpers.h"
void ACrappyFlapCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor == nullptr) || (OtherActor == this) || (OtherComp == nullptr))
	{
		return;
	}

	if (OtherComp->IsA(UPaperTileMapComponent::StaticClass())) {
		auto tilemapComponent = (class UPaperTileMapComponent*)OtherComp;

		auto hit = Hit.ImpactPoint;
		auto hitNormal = Hit.Normal;
		auto tilemapPos = OtherActor->GetActorLocation();
		auto tileHitPos = (hit - hitNormal) - tilemapPos;
		
		int posX = FMath::Round(tileHitPos.X / tilemapComponent->TileMap->TileWidth);
		int posY = FMath::Round(tileHitPos.Z / tilemapComponent->TileMap->TileHeight) *-1;

		auto tile = tilemapComponent->GetTile(posX, posY, 0);
		auto tileSet = tilemapComponent->TileMap->SelectedTileSet.Get();
		auto userData = tileSet->GetTileUserData(tile.GetTileIndex());

		auto calculatedPos = tilemapPos 
			+ FVector(tilemapComponent->TileMap->TileWidth * posX, 0, tilemapComponent->TileMap->TileHeight * (posY*-1));

		DrawDebugLine(
			GetWorld(),
			calculatedPos,
			calculatedPos - hitNormal,
			FColor(255, 0, 0),
			false,
			5
		);

		DrawDebugLine(
			GetWorld(),
			hit,
			hit - (hitNormal*10.0f),
			FColor(255, 0, 0),
			false,
			5
		);

		if (userData != NAME_None) {
			auto userDataString = userData.ToString();

			if (userData != "floor") {
				GetWorld()->ServerTravel(FString("/Game/Scoreboard/ScoreboardLevel"));
			}
		}
	}
}
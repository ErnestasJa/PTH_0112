// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/Character.h"
#include "CrappyFlapCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PARTEH_API ACrappyFlapCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Name of the Sprite component
	static FName SpriteComponentName;

private:
	/** The main skeletal mesh associated with this Character (optional sub-object). */
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* Sprite;

	/** The main skeletal mesh associated with this Character (optional sub-object). */
	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Speed;

public: 
	ACrappyFlapCharacter(const FObjectInitializer& ObjectInitializer);
	virtual void PostInitializeComponents() override;

	void Tick(float deltaSeconds) override;

	/** Returns Sprite subobject **/
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public: 
	FORCEINLINE void ResetJumpState() { Super::ResetJumpState(); }

protected:
	void HandleTileCollision(const FName & tileData);
};

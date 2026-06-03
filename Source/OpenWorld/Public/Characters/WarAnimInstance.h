// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "WarAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class OPENWORLD_API UWarAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	//1. Overwrite Initialization and Tick function
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;


	//2. Setup Character reference
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = WarCharacter)
	class AWarCharacter* WarCharacter;

	//3. Setup CharacterMovement Component, which is used to check if the state change
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = Movement)
	class UCharacterMovementComponent* WarCharacterMovement;

	//4. Use UCharacterMovementComponent to get the Speed
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = Movement)
	float GroundSpeed;

	//5. Check character is falling
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	bool IsFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Movement | Character State")
	ECharacterState CharacterState;
};

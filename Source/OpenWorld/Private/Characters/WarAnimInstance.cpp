// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WarAnimInstance.h"
#include "Characters/WarCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UWarAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	WarCharacter = Cast<AWarCharacter>(TryGetPawnOwner());
	if (WarCharacter)
	{
		WarCharacterMovement = WarCharacter->GetCharacterMovement();
	}
}

void UWarAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (WarCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(WarCharacterMovement->Velocity);
		IsFalling = WarCharacterMovement->IsFalling();
		CharacterState = WarCharacter->GetCharacterState();
	}
}

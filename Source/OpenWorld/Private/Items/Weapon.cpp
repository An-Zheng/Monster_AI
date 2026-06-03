// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapon.h"
#include "Characters/WarCharacter.h"

void AWeapon::Equip(USceneComponent* SceneComponent, FName SocketName)
{
	FAttachmentTransformRules transformRules(EAttachmentRule::SnapToTarget, true);
	itemMesh->AttachToComponent(SceneComponent, transformRules, SocketName);
}

void AWeapon::HandleBegionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::HandleBegionOverlap(OverlappedComponent,  OtherActor, OtherComp,  OtherBodyIndex,  bFromSweep, SweepResult);

}

void AWeapon::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::HandleEndOverlap( OverlappedComponent,  OtherActor,   OtherComp,  OtherBodyIndex);
}



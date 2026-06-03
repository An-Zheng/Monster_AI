// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "OpenWorld/DebugMarco.h"
#include "Components/SphereComponent.h"
#include "Characters/WarCharacter.h"
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = itemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SpherehComponent"));
	Sphere->SetupAttachment(itemMesh);

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::HandleBegionOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::HandleEndOverlap);
}

float AItem::TransformedSin()
{
	return amplitude * FMath::Sin(runningTime * timeConstant);
}

float AItem::TransformedCos()
{
	return amplitude * FMath::Cos(runningTime * timeConstant);
}

void AItem::HandleBegionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWarCharacter* WarCharacter = Cast<AWarCharacter>(OtherActor);
	if (WarCharacter)
	{
		WarCharacter->SetOverlappingItem(this);
	}
}

void AItem::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AWarCharacter* WarCharacter = Cast<AWarCharacter>(OtherActor);
	if (WarCharacter)
	{
		WarCharacter->SetOverlappingItem(nullptr);
	}
}



void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	runningTime += DeltaTime;

	float deltaZ = amplitude * FMath::Sin(runningTime * timeConstant);

	//float movementRate = 50.f;
	//float rotatorRate = 40.f;
	//
	//AddActorWorldOffset(FVector{ 0.f, 0.f, deltaZ});
	//AddActorWorldRotation(FRotator{ rotatorRate * DeltaTime, 0.f , 0.f });
	//DEBUG_SPHERE_SINGLE_FRAME(GetActorLocation());
	//DEBUG_VECTOR_SINGLE_FRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
}


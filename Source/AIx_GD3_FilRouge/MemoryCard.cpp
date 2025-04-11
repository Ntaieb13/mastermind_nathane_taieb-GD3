// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryCard.h"

// Sets default values
AMemoryCard::AMemoryCard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMemoryCard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMemoryCard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMemoryCard::TurnCard()
{

	bIsClickable = !bIsClickable;
	FRotator rot;
	if(GetActorRotation().Euler().X == 0)
	{
		rot = FRotator(180.0f,0.0f,0.0f);
		
	} else
	{
		rot = FRotator(0.0f,0.0f,0.0f);
	}
	SetActorRotation(rot);
}




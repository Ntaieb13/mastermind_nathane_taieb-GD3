// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryPC.h"

void AMemoryPC::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

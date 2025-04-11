// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MemoryCard.generated.h"

UCLASS()
class AIX_GD3_FILROUGE_API AMemoryCard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMemoryCard();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsClickable = true;

	

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void TurnCard();

	
};

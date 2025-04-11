// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MemoryCard.h"
#include "GameFramework/GameModeBase.h"
#include "MemoryGM.generated.h"

/**
 * 
 */
UCLASS()
class AIX_GD3_FILROUGE_API AMemoryGM : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Memory")
	int32 MemoryScore;
	UPROPERTY(editAnywhere,BlueprintReadWrite,Category="Memory")
	AMemoryCard* PreviousCard; 
public :
	UFUNCTION(BlueprintCallable)
	void UpdateScore(int32 value);
	UFUNCTION(BlueprintCallable)
	bool TestPair(int32 FirstCardValue, int32 SecondCardValue);
};

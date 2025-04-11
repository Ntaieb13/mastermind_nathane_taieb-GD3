// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterMindGM.h"

// Sets default values
AMasterMindGM::AMasterMindGM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterMindGM::BeginPlay()
{
	Super::BeginPlay();
	CreateSolution();
}

// Called every frame
void AMasterMindGM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FLinearColor AMasterMindGM::GetColor(uint8 ColorNumber)
{
	if(ColorNumber < Colors.Num())
	{
		return Colors[ColorNumber];
	}

	return FLinearColor::Black;
	
}


void AMasterMindGM::CreateSolution()
{
	Solution.SetNum(4);
	for(uint8 i = 0; i < 4; i++)
	{
		Solution[i] = FMath::RandRange(0,5);
	}
}

bool AMasterMindGM::CheckAnswer(TArray<uint8> Answer)
{
	bool result = true;
	uint8 GoodPlaces = 0;
	uint8 WrongPlaces = 0;
	TArray<bool> SolutionsAllowed {true,true,true,true};
	TArray<bool> AnswersAllowed {true,true,true,true};
	for(uint8 i = 0; i < 4; i++)
	{
		if(Solution[i] == Answer[i])
		{
			SolutionsAllowed[i] = false;
			AnswersAllowed[i] = false;
			GoodPlaces++;
		} else
		{
			result = false;
		}
	}
	// GoodPlaces contient le nombre de réponses bien placées


	// Recherche des réponses mal placées
	for(uint8 i = 0; i < 4; i++)
	{
		if(AnswersAllowed[i])
		{
			for(uint8 j = 0; j < 4; j++)
			{
				if(SolutionsAllowed[j] && Answer[i] == Solution[j])
				{
					WrongPlaces++;
					SolutionsAllowed[j] = false;
					break;
				}
			}
		}
	}

	OnSolutionChecked.Broadcast(GoodPlaces,WrongPlaces);
	UE_LOG(LogTemp,Warning,TEXT("CheckAnswer Done"));
	return result;
}


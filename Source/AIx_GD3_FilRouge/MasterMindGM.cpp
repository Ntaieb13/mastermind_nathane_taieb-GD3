// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterMindGM.h"

 void AMasterMindGM::CheckAnswer(TArray<uint8> Answer & PlayerGuess)
{:: 
	uint8 GoodPlace = 0;
	uint8 WrongPlace = 0;

	TArray<bool> UsedInCode;
	TArray<bool> UsedInGuess;
	UsedInCode.Init(false, 4);
	UsedInGuess.Init(false, 4);

	// Étape 1 : Bonnes couleurs à la bonne place
	for (int i = 0; i < 4; i++)
	{
		if (PlayerGuess[i] == SecretCode[i])
		{
			GoodPlace++;
			UsedInCode[i] = true;
			UsedInGuess[i] = true;
		}
	}

	// Étape 2 : Bonnes couleurs à la mauvaise place
	for (int i = 0; i < 4; i++)
	{
		if (UsedInGuess[i]) continue;

		for (int j = 0; j < 4; j++)
		{
			if (!UsedInCode[j] && PlayerGuess[i] == SecretCode[j])
			{
				WrongPlace++;
				UsedInCode[j] = true;
				break;
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Résultat : %d bien placés, %d mal placés"), GoodPlace, WrongPlace);

	OnSolutionChecked.Broadcast(GoodPlace, WrongPlace);
}

// Sets default values
AMasterMindGM::AMasterMindGM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterMindGM::BeginPlay()
{void AMasterMindGM::BeginPlay();
{
	Super::BeginPlay();

	// Exemple : générer une combinaison de 4 couleurs aléatoires (valeurs entre 0 et 5)
	SecretCode.SetNum(4);
	for (int i = 0; i < 4; ++i)
	{
		SecretCode[i] = FMath::RandRange(0, 5); // 6 couleurs possibles
	}

	UE_LOG(LogTemp, Log, TEXT("Code secret : %d %d %d %d"), SecretCode[0], SecretCode[1], SecretCode[2], SecretCode[3]);
}

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


#include "MastermindLogic.h"

void UMastermindLogic::GenerateSecretCode(int32 CodeLength, int32 MaxColorIndex)
{
	SecretCode.Empty();
	NumColors = MaxColorIndex;

	for (int32 i = 0; i < CodeLength; ++i)
	{
		int32 RandValue = FMath::RandRange(0, MaxColorIndex);
		SecretCode.Add(RandValue);
	}
}

void UMastermindLogic::CheckGuess(const TArray<int32>& PlayerGuess, int32& CorrectPlace, int32& CorrectColor)
{
	CorrectPlace = 0;
	CorrectColor = 0;

	TArray<bool> SecretMatched;
	TArray<bool> GuessMatched;
	SecretMatched.Init(false, SecretCode.Num());
	GuessMatched.Init(false, PlayerGuess.Num());

	// Étape 1 : Pions bien placés
	for (int32 i = 0; i < PlayerGuess.Num(); ++i)
	{
		if (PlayerGuess[i] == SecretCode[i])
		{
			CorrectPlace++;
			SecretMatched[i] = true;
			GuessMatched[i] = true;
		}
	}

	// Étape 2 : Pions mal placés
	for (int32 i = 0; i < PlayerGuess.Num(); ++i)
	{
		if (GuessMatched[i]) continue;

		for (int32 j = 0; j < SecretCode.Num(); ++j)
		{
			if (!SecretMatched[j] && PlayerGuess[i] == SecretCode[j])
			{
				CorrectColor++;
				SecretMatched[j] = true;
				break;
			}
		}
	}
}

TArray<int32> UMastermindLogic::GetSecretCode() const
{
	return SecretCode;
}

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MastermindLogic.generated.h"

UCLASS(Blueprintable)
class YOURPROJECT_API UMastermindLogic : public UObject
{
    GENERATED_BODY()

public:
    // Génère un nouveau code secret
    UFUNCTION(BlueprintCallable, Category = "Mastermind")
    void GenerateSecretCode(int32 CodeLength, int32 MaxColorIndex);

    // Vérifie un essai du joueur
    UFUNCTION(BlueprintCallable, Category = "Mastermind")
    void CheckGuess(const TArray<int32>& PlayerGuess, int32& CorrectPlace, int32& CorrectColor);

    // Lecture du code (pour test/debug)
    UFUNCTION(BlueprintCallable, Category = "Mastermind")
    TArray<int32> GetSecretCode() const;

private:
    TArray<int32> SecretCode;
    int32 NumColors;
};
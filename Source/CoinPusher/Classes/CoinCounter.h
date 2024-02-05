// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "CoinCounter.generated.h"

UCLASS()
class COINPUSHER_API UCoinCounter : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
        UTextBlock* MyTextBox;

public:
    // Function to set text for the text box
    void SetCoinsCollectedText(int coinsCollected);
};

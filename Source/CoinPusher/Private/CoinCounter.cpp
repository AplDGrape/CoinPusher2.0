// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinCounter.h"
#include "Components/TextBlock.h"

void UCoinCounter::SetCoinsCollectedText(int coinsCollected)
{
    if (MyTextBox)
    {
        FString TextToShow = FString::Printf(TEXT("Coins Collected: %d"), coinsCollected);
        MyTextBox->SetText(FText::FromString(TextToShow));
    }
}
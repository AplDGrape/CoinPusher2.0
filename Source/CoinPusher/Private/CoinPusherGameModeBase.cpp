// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPusherGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void ACoinPusherGameModeBase::BeginPlay()
{
	if (GameWidgetClass)
	{
		GameWidget = Cast<UCoinCounter>(CreateWidget(GetWorld(), GameWidgetClass));

		if (GameWidget)
		{
			GameWidget->AddToViewport();
			UpdateCoinsCollected(0);
		}
	}
}

void ACoinPusherGameModeBase::UpdateCoinsCollected(int coinsCollected)
{
	GameWidget->SetCoinsCollectedText(coinsCollected);
}

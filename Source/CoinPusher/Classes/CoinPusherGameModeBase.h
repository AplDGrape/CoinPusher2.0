// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoinCounter.h"
#include "CoinCollector.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CoinPusherGameModeBase.generated.h"

class UCoinCollector;
class UCoinCounter;

UCLASS()
class COINPUSHER_API ACoinPusherGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Widgets") TSubclassOf<class UUserWidget> GameWidgetClass;

	UPROPERTY()
	UCoinCounter* GameWidget;

	int CoinsCollected = 0;

	virtual void BeginPlay() override;

public:
	void UpdateCoinsCollected(int coinsCollected);
	
};

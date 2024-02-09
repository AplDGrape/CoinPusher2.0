// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "ObjectPoolComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CoinSpawner.generated.h"

class UObjectPoolComponent;

UCLASS()
class COINPUSHER_API ACoinSpawner : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ACoinSpawner();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int Num = 1;

private:
	UPROPERTY(EditAnywhere) FVector coinSize = FVector(0.5f, 0.5f, 0.04);

	UPROPERTY(EditAnywhere) USceneComponent* spawnerMeshComponent;

	UPROPERTY(EditAnywhere) AActor* spawnedCoin = NULL;

	UPROPERTY(EditAnywhere) AActor* objectPool = NULL; 

	UObjectPoolComponent* objectPoolComponent = NULL;

	UPROPERTY(EditAnywhere) float spawnBoundsY = 1.0f;

	void spawnCoin();

	//Spawn x number of coins
	void AmtCoin();
	//increase amount
	void Increase();
	//decrease amount
	void Decrease();

	FRotator getRandomizedRotation();
	FVector getRandomizedLocation();
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ObjectPoolComponent.h"
#include "ActorPoolable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinCollector.generated.h"

class AActorPoolable;
class UObjectPoolComponent;

UCLASS()
class COINPUSHER_API ACoinCollector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinCollector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* planeMesh = NULL;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere) AActor* objectPool = NULL;
	UObjectPoolComponent* objectPoolComponent = NULL;

	int CoinsCollected = 0;

public:
	int getCoinsCollected();
};

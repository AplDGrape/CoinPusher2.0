// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TheMovingObj.generated.h"

UCLASS()
class COINPUSHER_API ATheMovingObj : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATheMovingObj();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathing", meta = (ExposeOnSpawn = "true", MakeEditWidget = "true"))
	TArray<FVector> ThePath;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UBoxComponent* BoxCollider;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* MyMesh;

	//Deals Movement
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UInterpToMovementComponent* MovementComponent;
};

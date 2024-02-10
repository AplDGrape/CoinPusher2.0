// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomColour.generated.h"

UCLASS()
class COINPUSHER_API ARandomColour : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomColour();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*UPROPERTY(EditAnywhere, Category = "ColorMesh") class UStaticMeshComponent* MeshComponent;

	UPROPERTY()
	UMaterialInstanceDynamic* MaterialInstance;

	UPROPERTY()
	UMaterialInterface* m_Dynamic;

	UFunction(BlueprintCallable) void ChangeColour();*/
};

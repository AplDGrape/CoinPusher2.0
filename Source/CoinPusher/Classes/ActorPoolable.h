// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "ActorPoolable.generated.h"

UCLASS()
class COINPUSHER_API AActorPoolable : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorPoolable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnInitialize();
	virtual void OnRelease();
	virtual void OnActivate();

	void SetIndex(int i);
	int GetIndex();

	/*UPROPERTY(EditAnywhere, Category = "ColorMesh") class UStaticMeshComponent* MeshComponent;

	UPROPERTY()
	UMaterialInstanceDynamic* MaterialInstance;

	UPROPERTY()
	UMaterialInterface* m_Dynamic;

	UFUNCTION(BlueprintCallable) void ChangeColour();*/

private:
	int index = -1;

};

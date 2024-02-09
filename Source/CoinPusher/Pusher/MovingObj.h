// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Components/ActorComponent.h"

#include "MovingObj.generated.h"

UCLASS()
class COINPUSHER_API AMovingObj : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMovingObj();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathing", meta = (ExposeOnSpawn = "true", MakeEditWidget = "true"))
	TArray<FVector> ThePath;

	void Increase();
	void Decrease();

	float CurrentSpd = 0.0f;
	bool ObjSpd;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UBoxComponent* BoxCollider;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* MyMesh;

	//Deals Movement
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UInterpToMovementComponent* MovementComponent;

	//Handles Inputs
	//UPROPERTY(EditAnywhere) AActor* ObjSpeed = NULL;
};

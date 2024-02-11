// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Components/ActorComponent.h"

#include "MoveObj.generated.h"

UCLASS()
class COINPUSHER_API AMoveObj : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMoveObj();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathing", meta = (ExposeOnSpawn = "true", MakeEditWidget = "true"))
	TArray<FVector> ThePath;

	UFUNCTION(BlueprintCallable) void Increase();
	UFUNCTION(BlueprintCallable) void Decrease();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathing", meta = (ExposeOnSpawn = "true", MakeEditWidget = "true"))
	float CurrentSpd = 5;

	bool ObjSpd;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UBoxComponent* BoxCollider;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* MyMesh;

	//Deals Movement
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UInterpToMovementComponent* MovementComponent;
};

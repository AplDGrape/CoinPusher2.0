// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomColour.h"

// Sets default values
ARandomColour::ARandomColour()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARandomColour::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARandomColour::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ARandomColour::ChangeColour()
//{
//
//}
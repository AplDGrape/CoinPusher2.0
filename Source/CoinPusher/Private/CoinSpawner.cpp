// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinSpawner.h"
#include "Components/InputComponent.h"

// Sets default values for this component's properties
ACoinSpawner::ACoinSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;
	// ...

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	this->spawnerMeshComponent = (USceneComponent*)CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	this->spawnerMeshComponent->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


// Called when the game starts
void ACoinSpawner::BeginPlay()
{
	Super::BeginPlay();

	this->spawnedCoin->SetActorHiddenInGame(true);
	if(this->InputComponent != NULL)
		this->InputComponent->BindAction("SpawnCoin", IE_Pressed, this, &ACoinSpawner::spawnCoin);

	if (this->objectPool != NULL)
		this->objectPoolComponent = this->objectPool->FindComponentByClass<UObjectPoolComponent>();

}



// Called every frame
void ACoinSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACoinSpawner::spawnCoin()
{
	FActorSpawnParameters spawnParams;
	spawnParams.Template = this->spawnedCoin;
	spawnParams.Owner = this->GetOwner();

	FVector spawnLocation = this->getRandomizedLocation();
	FRotator spawnRotation = this->getRandomizedRotation();

	if (this->objectPoolComponent != NULL && this->objectPoolComponent->HasObjectAvailable(1)) {
		AActor* myCoin = this->objectPoolComponent->RequestPoolable();
		myCoin->AttachToActor(this->GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
		myCoin->SetActorHiddenInGame(false);
		myCoin->SetActorLocation(spawnLocation);
		myCoin->SetActorRotation(spawnRotation);
		myCoin->SetActorScale3D(this->coinSize);
	}
	else if (this->objectPoolComponent != NULL && !this->objectPoolComponent->HasObjectAvailable(1)) {
		this->objectPoolComponent->ReleasePoolableBatch(1);
	}
	else if(this->objectPoolComponent == NULL){
		UE_LOG(LogTemp, Error, TEXT("No Instance of objectPoolComponent exists."));
	}

}

FRotator ACoinSpawner::getRandomizedRotation()
{
	FRotator randomizedRotation;

	randomizedRotation.Pitch = (double)FMath::RandRange(0, 360);
	randomizedRotation.Yaw = (double)FMath::RandRange(0, 360);
	randomizedRotation.Roll = (double)FMath::RandRange(0, 360);

	return randomizedRotation;
}

FVector ACoinSpawner::getRandomizedLocation()
{
	FVector RandomizedSpawnLocation = this->GetActorLocation();
	FVector LowerBoundLoc = RandomizedSpawnLocation;
	FVector UpperBoundLoc = RandomizedSpawnLocation;

	LowerBoundLoc.Y -= this->spawnBoundsY;
	UpperBoundLoc.Y += this->spawnBoundsY;

	RandomizedSpawnLocation.Y = FMath::RandRange(LowerBoundLoc.Y, UpperBoundLoc.Y);

	return RandomizedSpawnLocation;
}

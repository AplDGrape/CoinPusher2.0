// Fill out your copyright notice in the Description page of Project Settings.

#include "CoinCollector.h"
#include "CoinPusherGameModeBase.h"

// Sets default values
ACoinCollector::ACoinCollector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	this->planeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collider"));
	this->planeMesh->SetupAttachment(RootComponent);

	

}

// Called when the game starts or when spawned
void ACoinCollector::BeginPlay()
{
	Super::BeginPlay();
	this->planeMesh->OnComponentHit.AddDynamic(this, &ACoinCollector::OnHit);

	if (this->objectPool != NULL)
		this->objectPoolComponent = this->objectPool->FindComponentByClass<UObjectPoolComponent>();
}

// Called every frame
void ACoinCollector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoinCollector::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	if (Cast<AActorPoolable>(OtherActor) != nullptr && this->objectPoolComponent != NULL) {
		AActorPoolable* OtherPoolableActor = Cast<AActorPoolable>(OtherActor);
		this->objectPoolComponent->ReleasePoolable(OtherPoolableActor);

		CoinsCollected++;

		ACoinPusherGameModeBase* GameMode = Cast<ACoinPusherGameModeBase>(GetWorld()->GetAuthGameMode());

		if (GameMode) {
			GameMode->UpdateCoinsCollected(CoinsCollected);
		}

	}
}

int ACoinCollector::getCoinsCollected()
{
	return this->CoinsCollected;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPoolComponent.h"

// Sets default values for this component's properties
UObjectPoolComponent::UObjectPoolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UObjectPoolComponent::BeginPlay()
{
	Super::BeginPlay();

	this->Initialize();

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Size: %d"), this->availableObjects.Num()));
	
}

void UObjectPoolComponent::BeginDestroy()
{
	Super::BeginDestroy();

	for (int i = 0; i < this->availableObjects.Num(); i++) {
		this->availableObjects[i]->Destroy();
	}

	for (int i = 0; i < this->usedObjects.Num(); i++) {
		this->usedObjects[i]->Destroy();
	}

	this->availableObjects.Empty();
	this->usedObjects.Empty();
}


// Called every frame
void UObjectPoolComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UObjectPoolComponent::Initialize()
{
	UE_LOG(LogTemp, Display, TEXT("This is Called"));

	if (this->coinCopy == NULL) {
		UE_LOG(LogTemp, Display, TEXT("Coin is null. Object Pool not initialized."));
		return;
	}

	FActorSpawnParameters spawnParams;
	spawnParams.Template = this->coinCopy;
	spawnParams.Owner = this->GetOwner();

	const FTransform transform = this->coinCopy->GetActorTransform();
	for (int i = 0; i < this->maxCoins; i++) {
		AActorPoolable* poolableObject = this->GetWorld()->SpawnActor<AActorPoolable>(this->coinCopy->GetClass(), spawnParams);
		poolableObject->SetIndex(i);
		poolableObject->OnInitialize();
		this->availableObjects.Push(poolableObject);
	}
}

bool UObjectPoolComponent::HasObjectAvailable(int requestSize)
{
	return this->availableObjects.Num() > requestSize;
}

int UObjectPoolComponent::GetMaxPoolSize()
{
	return this->maxCoins;
}

AActorPoolable* UObjectPoolComponent::RequestPoolable()
{
	if (this->HasObjectAvailable(1)) {
		AActorPoolable* object = this->availableObjects.Pop();
		object->SetIndex(this->usedObjects.Num());
		this->usedObjects.Push(object);
		object->OnActivate();
		object->SetActorTransform(this->GetOwner()->GetActorTransform());
		return object;
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("No more available objects."));
		return NULL;
	}
}

TArray<AActorPoolable*> UObjectPoolComponent::RequestPoolableBatch(int size)
{
	TArray<AActorPoolable*> objects;

	for (int i = 0; i < size && this->availableObjects.Num() > 0; i++) {
		objects.Push(this->RequestPoolable());
	}
	return objects;
}

void UObjectPoolComponent::ReleasePoolable(AActorPoolable* poolableObject)
{
	poolableObject->OnRelease();
	this->usedObjects.Remove(poolableObject);
	this->availableObjects.Push(poolableObject);
}

void UObjectPoolComponent::ReleasePoolableBatch(TArray<AActorPoolable*> objectList)
{
	for (int i = 0; i < objectList.Num(); i++) {
		this->ReleasePoolable(objectList[i]);
	}
}

void UObjectPoolComponent::ReleasePoolableBatch(int count)
{
	for (int i = 0; i < count; i++) {
		AActorPoolable* releasedObject = this->usedObjects[i];

		releasedObject->OnRelease();
		this->availableObjects.Push(releasedObject);
		this->usedObjects.Remove(releasedObject);
	}
}


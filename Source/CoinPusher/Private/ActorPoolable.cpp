// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPoolable.h"

//#include "UObject/ConstructorHelpers.h"
//#include "Engine.h"
////For randomsation
//#include "Kismet/KismetMathLibrary.h"

// Sets default values
AActorPoolable::AActorPoolable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	//RootComponent = MeshComponent;

	////Find material
	//static ConstructorHelpers::FObjectFinder<UMaterial> MAT(TEXT("/Script/Engine.Material'/Game/Material/CoinMat_01.CoinMat_01'"));

	////Making sure material is valid
	//if (MAT.Object != NULL)
	//{
	//	m_Dynamic = (UMaterial*)MAT.Object;
	//}

}

// Called when the game starts or when spawned
void AActorPoolable::BeginPlay()
{
	Super::BeginPlay();
	
	this->SetActorHiddenInGame(true);
	this->SetActorTickEnabled(false);
	this->FindComponentByClass<UPrimitiveComponent>()->SetSimulatePhysics(false);

	////check if m_Dynamic is set
	//if (m_Dynamic)
	//{
	//	MaterialInstance = UMaterialInstanceDynamic::Create(m_Dynamic, this);
	//}

	////check is that instance is checked
	//if (MaterialInstance)
	//{
	//	MeshComponent->SetMaterial(0, MaterialInstance);
	//}

}

// Called every frame
void AActorPoolable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AActorPoolable::ChangeColour()
//{
//	MaterialInstance->SetVectorParameterValue("RandomColour", FLinearColor(
//		UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f),		//Red
//		UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f),		//Green
//		UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f)));	//Blue
//}

void AActorPoolable::OnInitialize()
{
}

void AActorPoolable::OnRelease()
{
	this->SetActorHiddenInGame(true);
	this->SetActorTickEnabled(false);
	this->FindComponentByClass<UPrimitiveComponent>()->SetSimulatePhysics(false);
}

void AActorPoolable::OnActivate()
{
	this->SetActorHiddenInGame(false);
	this->SetActorTickEnabled(true);
	this->FindComponentByClass<UPrimitiveComponent>()->SetSimulatePhysics(true);
}

void AActorPoolable::SetIndex(int i)
{
	this->index = i;
}

int AActorPoolable::GetIndex()
{
	return 0;
}


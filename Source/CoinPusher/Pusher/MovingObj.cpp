// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObj.h"

#include "Components/BoxComponent.h"
#include "Components/InterpToMovementComponent.h"

// Sets default values
AMovingObj::AMovingObj()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = BoxCollider;

	//Creating the static mesh
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UInterpToMovementComponent>(TEXT("MovementComponent"));

	//Setting up default parameters
	MovementComponent->Duration = 5.0f;
	//Sweep for blocking collisions during movement
	MovementComponent->bSweep = true;
	//Back and forth movement
	MovementComponent->BehaviourType = EInterpToBehaviourType::PingPong;
}

// Called when the game starts or when spawned
void AMovingObj::BeginPlay()
{
	Super::BeginPlay();
	
	//Setting up control points for the movement
	MovementComponent->ControlPoints.Add(FInterpControlPoint(FVector(0.f, 0.f, 0.f), true));
	//Going through the paths
	for (int i = 0; i < ThePath.Num(); i++)
	{
		MovementComponent->ControlPoints.Add(FInterpControlPoint(ThePath[i], true));
	}
	//Run path
	MovementComponent->FinaliseControlPoints();
}

// Called every frame
void AMovingObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMovingObj::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


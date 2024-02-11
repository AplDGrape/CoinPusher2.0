// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveObj.h"

#include "Components/BoxComponent.h"
#include "Components/InterpToMovementComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AMoveObj::AMoveObj()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = BoxCollider;

	//Creating the static mesh
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UInterpToMovementComponent>(TEXT("MovementComponent"));

	//Setting up default parameters
	MovementComponent->Duration = CurrentSpd;
	//Sweep for blocking collisions during movement
	MovementComponent->bSweep = true;
	//Back and forth movement
	MovementComponent->BehaviourType = EInterpToBehaviourType::PingPong;

	//Get possession automatically
	AutoPossessPlayer = EAutoReceiveInput::Player1;

}

// Called when the game starts or when spawned
void AMoveObj::BeginPlay()
{
	Super::BeginPlay();
	
	if (this->InputComponent != NULL)
		this->InputComponent->BindAction("IncreaseSpeed", IE_Pressed, this, &AMoveObj::Increase);
	if (this->InputComponent != NULL)
		this->InputComponent->BindAction("DecreaseSpeed", IE_Pressed, this, &AMoveObj::Decrease);

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
void AMoveObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMoveObj::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("IncreaseSpeed", IE_Pressed, this, &AMoveObj::Increase);
	InputComponent->BindAction("DecreaseSpeed", IE_Pressed, this, &AMoveObj::Decrease);
}

void AMoveObj::Increase()
{
	//ObjSpd = true;
	//MovementComponent->Duration = CurrentSpd - 1.0f;
	/*if (CurrentSpd <= 1.f)
		CurrentSpd = 1.0f;
	else
		CurrentSpd--;*/
}

void AMoveObj::Decrease()
{
	CurrentSpd = CurrentSpd + 1.0f;
	if (CurrentSpd > 10.0f)
		CurrentSpd = 10.0f;

	MovementComponent->Duration = CurrentSpd;
}
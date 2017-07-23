// Fill out your copyright notice in the Description page of Project Settings.

#include "TankDestroy.h"
#include "Tank.h"
#include "TankMovement.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankMovementComp = CreateDefaultSubobject<UTankMovement>(TEXT("Move"));
	TankMovementComp->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("HorMove", this, &ATank::MoveY);
	InputComponent->BindAxis("VertMove", this, &ATank::MoveX);
	InputComponent->BindAxis("LookX", this, &ATank::LookX);
	InputComponent->BindAxis("LookY", this, &ATank::LookY);
	InputComponent->BindAction("ShootA", IE_Pressed, this, &ATank::ShootA);
	InputComponent->BindAction("Reload", IE_Pressed, this, &ATank::Reload);
	InputComponent->BindAction("ShootB", IE_Pressed, this, &ATank::ShootBPressed);
	InputComponent->BindAction("ShootB", IE_Released, this, &ATank::ShootBReleased);

}


UPawnMovementComponent* ATank::GetMovementComponent() const
{
	return TankMovementComp;
}


void ATank::MoveY(float val)
{
	if (TankMovementComp && (TankMovementComp->UpdatedComponent == RootComponent))
	{
		TankMovementComp->AddInputVector(GetActorForwardVector() * val);
	}
}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKDESTROY_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	virtual UPawnMovementComponent* GetMovementComponent() const override;

	UFUNCTION(Category = "Move", BlueprintCallable)
	void MoveY(float val);

	UFUNCTION(Category = "Move", BlueprintImplementableEvent, BlueprintCallable)
	void MoveX(float val);

	UFUNCTION(Category = "Look", BlueprintImplementableEvent, BlueprintCallable)
	void LookY(float val);

	UFUNCTION(Category = "Look", BlueprintImplementableEvent, BlueprintCallable)
	void LookX(float val);

	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
	void ShootA();

	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
	void Reload();

	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
	void ShootBPressed();

	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
	void ShootBReleased();

	class UTankMovement* TankMovementComp;
};

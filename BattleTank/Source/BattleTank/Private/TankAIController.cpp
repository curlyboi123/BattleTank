// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(PlayerTank && AimingComponent)) { return; }
	
	// TODO Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in centimeters

	// Aim towards the player
	
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// TODO fix firing
	AimingComponent->Fire(); // TODO limit firing
}




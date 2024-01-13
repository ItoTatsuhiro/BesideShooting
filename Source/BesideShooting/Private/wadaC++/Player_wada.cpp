// Fill out your copyright notice in the Description page of Project Settings.


#include "wadaC++/Player_wada.h"

// Sets default values
APlayer_wada::APlayer_wada()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayer_wada::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayer_wada::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer_wada::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


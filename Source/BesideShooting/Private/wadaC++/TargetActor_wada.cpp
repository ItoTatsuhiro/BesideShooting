// Fill out your copyright notice in the Description page of Project Settings.


#include "wadaC++/TargetActor_wada.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned

ATargetActor_wada::ATargetActor_wada() {
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = DefaultSceneRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/CPP_BP/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);


	StaticMesh->SetupAttachment(RootComponent);
}

void ATargetActor_wada::BeginPlay()
{
	Super::BeginPlay();

	FString Message = "C++ Hello World!";

	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Text‚ÌƒJƒ‰[î•ñ‚É•Ï”TextColor‚ğİ’è
		, Duration
		, TEXT("None"));
}

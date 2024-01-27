// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h" // ’Ç‰Á
#include "Components/PointLightComponent.h" // ’Ç‰Á
#include "TargetActor_wada.generated.h"

UCLASS()
class BESIDESHOOTING_API ATargetActor_wada : public AActor
{
	GENERATED_BODY()
	
public:	
	ATargetActor_wada();

	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	const float Duration = 10.0f;
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

};

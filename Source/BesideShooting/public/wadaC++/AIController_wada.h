// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController_wada.generated.h"

/**
 * 
 */
UCLASS()
class BESIDESHOOTING_API AAIController_wada : public AAIController
{
	GENERATED_BODY()
	
	AAIController_wada();
public:
	AActor* TargetActor;
	AActor* GetActor();

protected:
	virtual void BeginPlay() override;

};

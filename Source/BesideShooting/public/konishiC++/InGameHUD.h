// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include"ItoC++/PlayerCharacter.h"
#include "InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class BESIDESHOOTING_API AInGameHUD : public AHUD
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	
};

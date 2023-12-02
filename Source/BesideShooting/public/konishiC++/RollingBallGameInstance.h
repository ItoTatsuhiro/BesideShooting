// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RollingBallGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BESIDESHOOTING_API URollingBallGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	/** ‰Šú‰»‚·‚é */
	void Initialize();

public:
	/** æ“¾‚µ‚½ƒRƒCƒ“‚Ì” */
	int32 TotalCoins = 0;

	/** Player‚ÌLife **/
	int32 TotalLifes = 3;
};

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
	/** ���������� */
	void Initialize();

public:
	/** �擾�����R�C���̐� */
	int32 TotalCoins = 0;

	/** Player��Life **/
	int32 TotalLifes = 3;
};

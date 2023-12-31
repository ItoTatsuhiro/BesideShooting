// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "konishiC++/BallPlayer.h"
#include "MyPlayerController.generated.h"



/**
 * 
 */
UCLASS()
class BESIDESHOOTING_API AMyPlayerController : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Constructor
	AMyPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	/** Playerを破棄する **/
	void KillPlayer(ABallPlayer* Player);

	/** GameをRestartする **/
	void RestartGame();

	/** 取得したコインの枚数を追加する */
	int AddCoin(const int32 CoinNumber);

	// PlayerをRespawnする位置情報
	FTransform SpawnTransform;

private:
	/** PlayerをRespawnする **/
	void RespawnPlayer();
};
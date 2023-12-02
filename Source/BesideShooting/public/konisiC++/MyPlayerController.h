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
	/** Player‚ğ”jŠü‚·‚é **/
	void KillPlayer(ABallPlayer* Player);

	/** Game‚ğRestart‚·‚é **/
	void RestartGame();

	/** æ“¾‚µ‚½ƒRƒCƒ“‚Ì–‡”‚ğ’Ç‰Á‚·‚é */
	int AddCoin(const int32 CoinNumber);

	// Player‚ğRespawn‚·‚éˆÊ’uî•ñ
	FTransform SpawnTransform;

private:
	/** Player‚ğRespawn‚·‚é **/
	void RespawnPlayer();
};
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
	/** Player��j������ **/
	void KillPlayer(ABallPlayer* Player);

	/** Game��Restart���� **/
	void RestartGame();

	/** �擾�����R�C���̖�����ǉ����� */
	int AddCoin(const int32 CoinNumber);

	// Player��Respawn����ʒu���
	FTransform SpawnTransform;

private:
	/** Player��Respawn���� **/
	void RespawnPlayer();
};
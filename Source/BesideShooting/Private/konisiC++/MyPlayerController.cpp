// Fill out your copyright notice in the Description page of Project Settings.


#include "konisiC++/MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "konishiC++/RollingBallGameInstance.h"
#include "konishiC++/InGameHUD.h"

AMyPlayerController::AMyPlayerController()
{
	DefaultPawnClass = ABallPlayer::StaticClass();
	HUDClass = AInGameHUD::StaticClass();
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Viewport�ɔz�u���ꂽPlayerStart��T��
	const APlayerStart* PlayerStart = Cast<APlayerStart>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass()));

	// PlayerStart�̈ʒu����Resporn�̈ʒu�Ƃ��ĕێ�����
	SpawnTransform = PlayerStart->GetActorTransform();
}

void AMyPlayerController::KillPlayer(ABallPlayer* Player)
{
	// Player��j������
	Player->Destroy();

	// GameInstance���擾����
	APlayerCharacter* GameInstance = Cast<APlayerCharacter>(UGameplayStatics::GetGameInstance(GetWorld()));

	// TotalLifes��Decriment����
	//GameInstance->TotalLifes--;

	//if (0 <= GameInstance->TotalLifes)
	//{
	//	// Respawn���s��
	//	RespawnPlayer();
	//}
	//else
	//{
	//	// Game��Restart����
	//	UE_LOG(LogTemp, Display, TEXT("GameOver"));
	//	RestartGame();
	//}
}

void AMyPlayerController::RestartGame()
{
	// GameInstance���擾����
	URollingBallGameInstance* GameInstance = Cast<URollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// GameInstance�̕ϐ�������������
	GameInstance->Initialize();

	// ���݂�LevelName���擾����
	FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());

	// ���݂�Level���J���Ȃ���
	UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
}

int AMyPlayerController::AddCoin(const int32 CoinNumber)
{
	// GameInstance���擾����
	URollingBallGameInstance* GameInstance = Cast<URollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// �擾�����R�C���̖�����ǉ�����
	GameInstance->TotalCoins = GameInstance->TotalCoins + CoinNumber;

	return GameInstance->TotalCoins;
}

void AMyPlayerController::RespawnPlayer()
{
	// BallPlayer��Spawn����
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	ABallPlayer* Player = GetWorld()->SpawnActor<ABallPlayer>(ABallPlayer::StaticClass(), SpawnTransform, SpawnInfo);

	// Controller��ݒ肷��
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerController->Possess(Player);
}
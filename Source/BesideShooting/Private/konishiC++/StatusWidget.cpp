// Fill out your copyright notice in the Description page of Project Settings.


#include "konishiC++/StatusWidget.h"
#include "Components/TextBlock.h"
#include "konishiC++/BallPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "konishiC++/RollingBallGameInstance.h"

void UStatusWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

bool UStatusWidget::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success) return false;

	/*TextBlockHealth->TextDelegate.BindUFunction(this, "SetTextBlockHealth");
	TextBlockHealthMax->TextDelegate.BindUFunction(this, "SetTextBlockHealthMax");
	TextBlockTotalLifes->TextDelegate.BindUFunction(this, "SetTextBlockTotalLifes");
	TextBlockTotalCoins->TextDelegate.BindUFunction(this, "SetTextBlockTotalCoins");*/

	return true;
}

FText UStatusWidget::SetTextBlockHealth()
{
	// BallPlayer���擾����
	if (const ABallPlayer* Player = Cast<ABallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		// Player��Health��Text�ɐݒ肷��
		return FText::FromString(FString::FromInt((int)Player->GetHealth()));
	}

	return FText();
}

FText UStatusWidget::SetTextBlockHealthMax()
{
	// BallPlayer���擾����
	if (const ABallPlayer* Player = Cast<ABallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		// Player��Health��Text�ɐݒ肷��
		return FText::FromString(FString::FromInt((int)Player->GetHealthMax()));
	}

	return FText();
}

FText UStatusWidget::SetTextBlockTotalLifes()
{
	// GameInstance���擾����
	if (const URollingBallGameInstance* GameInstance = Cast<URollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		// GameInstance��TotalLifes��Text�ɐݒ肷��
		return FText::FromString(FString::FromInt(GameInstance->TotalLifes));
	}

	return FText();
}

FText UStatusWidget::SetTextBlockTotalCoins()
{
	// GameInstance���擾����
	if (const URollingBallGameInstance* GameInstance = Cast<URollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		// GameInstance��TotalCoins��Text�ɐݒ肷��
		return FText::FromString(FString::FromInt(GameInstance->TotalCoins));
	}

	return FText();
}


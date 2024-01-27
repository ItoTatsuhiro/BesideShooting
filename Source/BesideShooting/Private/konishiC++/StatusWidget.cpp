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

	TextBlockHealth->TextDelegate.BindUFunction(this, "SetTextBlockHealth");
	TextBlockHealthMax->TextDelegate.BindUFunction(this, "SetTextBlockHealthMax");
	/*TextBlockDistance->TextDelegate.BindUFunction(this, "SetTextBlockDistance");
	TextBlockMeter->TextDelegate.BindUFunction(this, "SetTextMeter");*/

	return true;
}

FText UStatusWidget::SetTextBlockHealth()
{
	// BallPlayer‚ğæ“¾‚·‚é
	if (const ABallPlayer* Player = Cast<ABallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		// Player‚ÌHealth‚ğText‚Éİ’è‚·‚é
		return FText::FromString(FString::FromInt((int)Player->GetHealth()));
	}

	return FText();
}

FText UStatusWidget::SetTextBlockHealthMax()
{
	// BallPlayer‚ğæ“¾‚·‚é
	if (const ABallPlayer* Player = Cast<ABallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		// Player‚ÌHealth‚ğText‚Éİ’è‚·‚é
		return FText::FromString(FString::FromInt((int)Player->GetHealthMax()));
	}

	return FText();
}

//FText UStatusWidget::SetTextBlockDistance()
//{
//	// GameInstance‚ğæ“¾‚·‚é
//	if (const URollingBallGameInstance* GameInstance = Cast<URollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
//	{
//		// GameInstance‚ÌTotalLifes‚ğText‚Éİ’è‚·‚é
//		return FText::FromString(FString::FromInt(GameInstance->TotalLifes));
//	}
//
//	return FText();
//}

FText UStatusWidget::SetTextMeter()
{
	// GameInstance‚ğæ“¾‚·‚é
	if (const URollingBallGameInstance* GameInstance = Cast<URollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		// GameInstance‚ÌTotalCoins‚ğText‚Éİ’è‚·‚é
		return FText::FromString(FString::FromInt(GameInstance->TotalCoins));
	}

	return FText();
}

void UStatusWidget::HandleDistanceUpdated(float NewDistance)
{

	//ì¬“ú@2024 : 1 / 27
	//PlayerCharacter‚Ìæ“¾
	if (APlayerCharacter* Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		Player->OnDistanceUpdated().AddUObject(this, &UStatusWidget::HandleDistanceUpdated);
	}


	if (UWidget* Widget = GetWidgetFromName(TEXT("TextBlockDistance"))) {
		if (UTextBlock* DistanceTextBlock = Cast<UTextBlock>(Widget))
		{
			TextBlockDistance->SetText(FText::FromString(FString::Printf(TEXT("Distance: %.2f"), NewDistance)));
		}
	}
	


}


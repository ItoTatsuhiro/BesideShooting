// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StatusWidget.generated.h"

class UTextBlock;


UCLASS()
class BESIDESHOOTING_API UStatusWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlockHealth;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlockHealthMax;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlockTotalLifes;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlockTotalCoins;

	UFUNCTION()
		FText SetTextBlockHealth();

	UFUNCTION()
		FText SetTextBlockHealthMax();

	UFUNCTION()
		FText SetTextBlockTotalLifes();

	UFUNCTION()
		FText SetTextBlockTotalCoins();
	
};

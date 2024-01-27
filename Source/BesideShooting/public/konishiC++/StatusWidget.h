// Fill out your copyright notice in the Description page of Project Settings.
///
/// çÏê¨ì˙Å@2024 : 11 / 18 Å`
/// çÏê¨é“Å@è¨êº
///

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"ItoC++/PlayerCharacter.h"
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

	/*UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlockDistance;*/

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlockMeter;

	UFUNCTION()
		FText SetTextBlockHealth();

	UFUNCTION()
		FText SetTextBlockHealthMax();

	/*UFUNCTION()
		FText SetTextBlockDistance();*/

	UFUNCTION()
		FText SetTextMeter();
	
public:
	 
	UFUNCTION()
		void HandleDistanceUpdated(float NewDistance);

	class UTextBlock* TextBlockDistance;

};

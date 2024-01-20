// Fill out your copyright notice in the Description page of Project Settings.


#include "konishiC++/InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void AInGameHUD::BeginPlay()
{
	//widgetBlueprint��class���擾����
	FString StatusWidgetPath = TEXT("/Game/konishiryouga/UI/BPW_Status.BPW_Status_C");
	TSubclassOf<UUserWidget>StatusWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*StatusWidgetPath)).LoadSynchronous();

	//PlyerController���擾����
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	// WidgetClass��PlayerController���擾�ł��������肷��
	
	if (StatusWidgetClass && PlayerController)
	{
		
		// Status�\���p��Widget���쐬����
		UUserWidget* StatusWidget = UWidgetBlueprintLibrary::Create(GetWorld(), StatusWidgetClass, PlayerController);

		// Viewport�ɒǉ�����
		StatusWidget->AddToViewport(0);
	}
}

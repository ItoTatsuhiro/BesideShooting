// Fill out your copyright notice in the Description page of Project Settings.


#include "konishiC++/InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void AInGameHUD::BeginPlay()
{
	//widgetBlueprintのclassを取得する
	FString StatusWidgetPath = TEXT("/Game/konishiryouga/UI/BPW_Status.BPW_Status_C");
	TSubclassOf<UUserWidget>StatusWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*StatusWidgetPath)).LoadSynchronous();

	//PlyerControllerを取得する
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	// WidgetClassとPlayerControllerが取得できたか判定する
	
	if (StatusWidgetClass && PlayerController)
	{
		
		// Status表示用のWidgetを作成する
		UUserWidget* StatusWidget = UWidgetBlueprintLibrary::Create(GetWorld(), StatusWidgetClass, PlayerController);

		// Viewportに追加する
		StatusWidget->AddToViewport(0);
	}
}

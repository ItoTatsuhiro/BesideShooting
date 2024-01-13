// Fill out your copyright notice in the Description page of Project Settings.


#include "wadaC++/AIC_Enemy.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>

void AAIC_Enemy::BeginPlay() {
	Super::BeginPlay();

	// Blackboard�Ƀv���C���[��TaragetActor�Ƃ��ēo�^
	auto pBlackBoard = GetBlackboardComponent();
	if (pBlackBoard) {
		pBlackBoard->SetValueAsObject(TEXT("TaragetActor"), UGameplayStatics::GetPlayerPawn(this, 0));
	}
}

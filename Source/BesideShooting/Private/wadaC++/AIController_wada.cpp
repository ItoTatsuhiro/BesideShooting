// Fill out your copyright notice in the Description page of Project Settings.


#include "wadaC++/AIController_wada.h"
#include "wadaC++/TargetActor_wada.h"
#include "ItoC++/PlayerCharacter.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>

AAIController_wada::AAIController_wada() {

}

AActor* AAIController_wada::GetActor() {
	TArray<AActor*> foundactors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetActor_wada::StaticClass(), foundactors);

	if (foundactors.Num() > 0) {
		return foundactors[0];
	}

	return nullptr;
}

void AAIController_wada::BeginPlay() {
	Super::BeginPlay();

	TargetActor = GetActor();

	//Blackboard‚ÉƒvƒŒƒCƒ„[‚ðTargetActor‚Æ‚µ‚Ä“o˜^
	auto pBlackBoard = GetBlackboardComponent();
	if (pBlackBoard) {
		pBlackBoard->SetValueAsObject(TEXT("TargetActor"), UGameplayStatics::GetPlayerPawn(this, 0));
	}
}


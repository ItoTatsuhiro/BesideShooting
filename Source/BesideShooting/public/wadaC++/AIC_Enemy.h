#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIC_Enemy.generated.h"

UCLASS()
class BESIDESHOOTING_API AAIC_Enemy : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};


// 作成者：伊藤龍拓
// 作成日：2023 / 11 / 18 ～　

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "konishiC++/RollingBallGameInstance.h"
#include "PlayerCharacter.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BESIDESHOOTING_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

	//---------------------------------------------------------------------------
	// プレイヤー関連

	/** Character用のStaticMesh : Plane */
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Plane;

	/** プレイヤーの接触判定用のCollision : Cube */
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"));
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	//---------------------------------------------------------------------------
	// カメラ関連
	//UPROPERTY(EditAnywhere)
	//	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* CameraComp;

	//UPROPERTY(EditAnywhere)
	//	UStaticMeshComponent* StaticMeshComp;


public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	// オブジェクトの回転量
	FRotator rotVal_;
	// 入力用の変数
	FVector curVel_;



public:	


	//作成日 2024 : 1 / 27
	//作成者　小西
	//プレイヤーの距離を取得する
	DECLARE_EVENT_OneParam(APlayerCharacter, FDistanceUpdatedEvent, float);
	FDistanceUpdatedEvent& OnDistanceUpdated() { return DistanceUpdatedEvent; }


	void Move_XAxis(float val);
	void Move_YAxis(float val);


private:

	//作成日 2024 : 1 / 27
	//作成者　小西
	//距離を計算した際に呼ぶイベント
	FDistanceUpdatedEvent DistanceUpdatedEvent;
	float CurrentDistance;

};

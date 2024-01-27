
// �쐬�ҁF�ɓ�����
// �쐬���F2023 / 11 / 18 �`�@

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
	// �v���C���[�֘A

	/** Character�p��StaticMesh : Plane */
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Plane;

	/** �v���C���[�̐ڐG����p��Collision : Cube */
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"));
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	//---------------------------------------------------------------------------
	// �J�����֘A
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



	// �I�u�W�F�N�g�̉�]��
	FRotator rotVal_;
	// ���͗p�̕ϐ�
	FVector curVel_;



public:	


	//�쐬�� 2024 : 1 / 27
	//�쐬�ҁ@����
	//�v���C���[�̋������擾����
	DECLARE_EVENT_OneParam(APlayerCharacter, FDistanceUpdatedEvent, float);
	FDistanceUpdatedEvent& OnDistanceUpdated() { return DistanceUpdatedEvent; }


	void Move_XAxis(float val);
	void Move_YAxis(float val);


private:

	//�쐬�� 2024 : 1 / 27
	//�쐬�ҁ@����
	//�������v�Z�����ۂɌĂԃC�x���g
	FDistanceUpdatedEvent DistanceUpdatedEvent;
	float CurrentDistance;

};

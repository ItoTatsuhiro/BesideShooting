// Fill out your copyright notice in the Description page of Project Settings.
//
// �쐬���@2023 / 11 / 18
// �쐬�ҁ@����
//

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "BallPlayer.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UArrowComponent;
class UInputMappingContext;
class UInputAction;


UCLASS()
class BESIDESHOOTING_API ABallPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABallPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Hit Event��Binding����֐�
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Player��Damage��^���� */
	float TakeDamagePlayer(const float Damage);

	/** Player��Rebound������ */
	void Rebound(const float ReboundPower);

	/** Player���񕜂����� */
	float Heal(const float Value);

	float GetHealth() const { return Health; }

	float GetHealthMax() const { return HealthMax; }


	//�쐬�� : 2024 / 1 / 27
	//�t���[���Ԃ̈ړ��ʂ��i�[����ϐ�
	//FVector LastFrameLocation;

	////Called every frame
	//virtual void Tick(float DeltaTime)override;


protected:
	/** Ball��Control���� */
	void ControlBall(const FInputActionValue& Value);

	/** ���_�𑀍삷�� */
	void Look(const FInputActionValue& Value);

	// �W�����v����
	void Jump(const FInputActionValue& Value);

	// ��������
	void Boost(const FInputActionValue& Value);

	


private:
	/** Character�p��StaticMesh : Sphere */
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UStaticMeshComponent> Sphere;

	/** Camera��z�u���邽�߂�SpringArm */
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<USpringArmComponent> SpringArm;

	/** SpringArm�̐�[�ɔz�u����J���� */
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UCameraComponent> Camera;

	/** �i�s������\������ArrowComponent */
	UPROPERTY(VisibleAnywhere, Category = Control, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UArrowComponent> Arrow;

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/** Control Input Action */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> ControlAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> LookAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> JumpAction;

	/** Boost Input Action */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> BoostAction;

	// ���x
	float Speed = 300.0f;

	// �̗�
	float Health = 100.0f;

	// �ő�̗�
	float HealthMax = 100.0f;

	// �W�����v�ɉ������
	float JumpImpluse = 500.0f;

	// �W�����v���ł��邩���肷��t���O
	bool CanJump = false;

	// �������鑁��
	float Torque = 500000000.0f;
};
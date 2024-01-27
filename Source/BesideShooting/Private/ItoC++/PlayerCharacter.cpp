
// �쐬�ҁF�ɓ�����
// �쐬���F2023 / 11 / 18 �`�@

#include "ItoC++/PlayerCharacter.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("RootComponent"));

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	// �J�����̐ݒ�
	CameraComp->SetupAttachment(RootComponent);
	// CameraComp->SetRelativeLocation(FVector(0.0f, 600.0f, 250.0f));
	CameraComp->SetRelativeRotation(FRotator(-7.0f, -90.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);

	// StaticMeshComponent��ǉ����ARootComponent�ɐݒ�
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Plane;
	// ������Movable�ɕύX
	RootComponent->SetMobility(EComponentMobility::Movable);

	// StaticMesh��Load����StaticMeshComponent��StaticMesh�ɐݒ�
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane"));
	// StaticMesh��StaticMeshComponent�ɐݒ�
	Plane->SetStaticMesh(Mesh);


	// �}�e���A�����X�^�e�B�b�N���b�V���ɐݒ�
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Game/ItoTatsuhiro/boy_Mat.boy_Mat"));
	// �}�e���A�����X�^�e�B�b�N���b�V���R���|�[�l���g�ɐݒ�
	Plane->SetMaterial(0, Material);
	// SimulatePhysics��L���ɂ���
	Plane->SetSimulatePhysics(true);
	// ������static�ɕύX
	 Plane->SetMobility(EComponentMobility::Movable);
	
	// BoxCollision�̒ǉ�
	Box = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Box->SetupAttachment(RootComponent);
	
	// �����̓K�p
	Box->SetEnableGravity(true);
	// �傫���̕ύX
	Box->SetRelativeScale3D(FVector(1.2f, 1.2f, 1.2f));

	 Box->SetMobility(EComponentMobility::Movable);
	// ��]�ʂ�ύX
	rotVal_ = FRotator(0.0f, 0.0f, 90.0f);

	// ��]�ʂ�ݒ�
	AddActorLocalRotation(rotVal_, false, 0, ETeleportType::TeleportPhysics);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �J�����̍��W���v���C���[�̈ʒu�ɍ��킹�Ĉړ�
	CameraComp->SetRelativeLocation( Plane->GetRelativeLocation() + FVector(0.0f, 600.0f, 100.0f));

	// �v���C���[�̈ړ�
	if (!curVel_.IsZero()) {
		FVector NextLocation = GetActorLocation() + (curVel_ * DeltaTime);
		SetActorLocation(NextLocation);

		// �ړ��������v�����A�C�x���g�Œʒm
		CurrentDistance += curVel_.Size() * DeltaTime;
		OnDistanceUpdated().Broadcast(CurrentDistance);

	}

}

void APlayerCharacter::Move_XAxis(float AxisVal) {

	curVel_.X = FMath::Clamp(AxisVal, -1.0f, 1.0f) * 100.0f;

}

void APlayerCharacter::Move_YAxis(float AxisVal) {

	curVel_.Y = FMath::Clamp(AxisVal, -1.0f, 1.0f) * 100.0f;

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &APlayerCharacter::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &APlayerCharacter::Move_YAxis);
}



// 作成者：伊藤龍拓
// 作成日：2023 / 11 / 18 ～　

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

	// カメラの設定
	CameraComp->SetupAttachment(RootComponent);
	// CameraComp->SetRelativeLocation(FVector(0.0f, 600.0f, 250.0f));
	CameraComp->SetRelativeRotation(FRotator(-7.0f, -90.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);

	// StaticMeshComponentを追加し、RootComponentに設定
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Plane;
	// 可動性をMovableに変更
	RootComponent->SetMobility(EComponentMobility::Movable);

	// StaticMeshをLoadしてStaticMeshComponentのStaticMeshに設定
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane"));
	// StaticMeshをStaticMeshComponentに設定
	Plane->SetStaticMesh(Mesh);


	// マテリアルをスタティックメッシュに設定
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Game/ItoTatsuhiro/boy_Mat.boy_Mat"));
	// マテリアルをスタティックメッシュコンポーネントに設定
	Plane->SetMaterial(0, Material);
	// SimulatePhysicsを有効にする
	Plane->SetSimulatePhysics(true);
	// 可動性をstaticに変更
	 Plane->SetMobility(EComponentMobility::Movable);
	
	// BoxCollisionの追加
	Box = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Box->SetupAttachment(RootComponent);
	
	// 物理の適用
	Box->SetEnableGravity(true);
	// 大きさの変更
	Box->SetRelativeScale3D(FVector(1.2f, 1.2f, 1.2f));

	 Box->SetMobility(EComponentMobility::Movable);
	// 回転量を変更
	rotVal_ = FRotator(0.0f, 0.0f, 90.0f);

	// 回転量を設定
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

	// カメラの座標をプレイヤーの位置に合わせて移動
	CameraComp->SetRelativeLocation( Plane->GetRelativeLocation() + FVector(0.0f, 600.0f, 100.0f));

	// プレイヤーの移動
	if (!curVel_.IsZero()) {
		FVector NextLocation = GetActorLocation() + (curVel_ * DeltaTime);
		SetActorLocation(NextLocation);

		// 移動距離を計測し、イベントで通知
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


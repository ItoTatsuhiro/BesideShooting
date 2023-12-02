// Fill out your copyright notice in the Description page of Project Settings.


#include "konishiC++/BallPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h" 
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABallPlayer::ABallPlayer()
{
	// StaticMeshComponent��ǉ����ARootComponent�ɐݒ肷��
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Sphere;

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	Sphere->SetStaticMesh(Mesh);

	// Material��StaticMesh�ɐݒ肷��
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));

	// Material��StaticMeshComponent�ɐݒ肷��
	Sphere->SetMaterial(0, Material);

	// Simulate Physics��L���ɂ���
	Sphere->SetSimulatePhysics(true);

	// CollisionPreset���uPhysicsActor�v�ɕύX����
	Sphere->SetCollisionProfileName(TEXT("PhysicsActor"));

	// Hit Event��L���ɂ���
	Sphere->BodyInstance.bNotifyRigidBodyCollision = true;

	// SpringArm��ǉ�����
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	// Spring Arm�̒����𒲐�����
	SpringArm->TargetArmLength = 450.0f;

	// Pawn��ControllerRotation���g�p����
	SpringArm->bUsePawnControlRotation = true;

	// Camera��Lag��L���ɂ���
	SpringArm->bEnableCameraLag = true;

	// Camera��ǉ�����
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);

	// MotionBlur���I�t�ɂ���
	Camera->PostProcessSettings.MotionBlurAmount = 0.0f;

	// Arrow��ǉ�����
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetupAttachment(Camera);

	// Sphere�̓���Ɉړ�����悤��Location��ݒ肷��
	Arrow->SetRelativeLocation(FVector(400.0f, 0.0f, 130.0f));

	// Arrow��\�������悤�ɂ���
	Arrow->bHiddenInGame = false;

	// Input Mapping Context�uIM_Controls�v��ǂݍ���
	DefaultMappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT("/Game/RollingBall/Input/IM_Controls"));

	// Input Action�uIA_Control�v��ǂݍ���
	ControlAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Control"));

	// Input Action�uIA_Look�v��ǂݍ���
	LookAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Look"));

	// Input Action�uIA_Jump�v��ǂݍ���
	JumpAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Jump"));

	// Input Action�uIA_Boost�v��ǂݍ���
	BoostAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Boost"));
}

// Called when the game starts or when spawned
void ABallPlayer::BeginPlay()
{
	Super::BeginPlay();

	//Add Input Mapping Context
	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ABallPlayer::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	CanJump = true;
}

// Called to bind functionality to input
void ABallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		// ControlBall��IA_Control��Triggered��Bind����
		EnhancedInputComponent->BindAction(ControlAction, ETriggerEvent::Triggered, this, &ABallPlayer::ControlBall);

		// Look��IA_Look��Triggered��Bind����
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABallPlayer::Look);

		// Jump��IA_Jump��Triggered��Bind����
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ABallPlayer::Jump);

		// Boost��IA_Boost��Triggered��Bind����
		EnhancedInputComponent->BindAction(BoostAction, ETriggerEvent::Triggered, this, &ABallPlayer::Boost);
	}
}

void ABallPlayer::ControlBall(const FInputActionValue& Value)
{
	// input��Value��Vector2D�ɕϊ��ł���
	const FVector2D V = Value.Get<FVector2D>();

	// Vector���v�Z����
	FVector ForceVector = FVector(V.Y, V.X, 0.0f) * Speed;

	// Arrow�̐i�s������Vector���v�Z����
	FVector ArrowForceVector = Arrow->GetComponentToWorld().TransformVectorNoScale(ForceVector);
	//UKismetMathLibrary::TransformDirection(Arrow->GetComponentToWorld(), ForceVector);

	// Sphere�ɗ͂�������
	Sphere->AddForce(ArrowForceVector, TEXT("NONE"), true);
}

void ABallPlayer::Look(const FInputActionValue& Value)
{
	// input��Value��Vector2D�ɕϊ��ł���
	const FVector2D V = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(V.X);
		AddControllerPitchInput(V.Y);

		// Pawn�������Ă���Control�̊p�x���擾����
		FRotator ControlRotate = GetControlRotation();

		// controller��Pitch�̊p�x�𐧌�����
		double LimitPitchAngle = FMath::ClampAngle(ControlRotate.Pitch, -40.0f, -10.0f);

		// PlayerController�̊p�x��ݒ肷��
		UGameplayStatics::GetPlayerController(this, 0)->SetControlRotation(FRotator(LimitPitchAngle, ControlRotate.Yaw, 0.0f));
	}
}

void ABallPlayer::Jump(const FInputActionValue& Value)
{
	// input��Value��bool�ɕϊ��ł���
	if (const bool V = Value.Get<bool>() && CanJump)
	{
		Sphere->AddImpulse(FVector(0.0f, 0.0f, JumpImpluse), TEXT("None"), true);
		CanJump = false;
	}
}

void ABallPlayer::Boost(const FInputActionValue& Value)
{
	// input��Value��bool�ɕϊ��ł���
	if (const bool V = Value.Get<bool>())
	{
		// Arrow�������Ă���O��������Vector�����擾����
		FVector ForwardVector = Arrow->GetForwardVector().GetSafeNormal(0.0001f);

		// Torque�Ƃ��ė^����Vector���쐬����
		FVector TorqueVector = FVector(ForwardVector.Y * Torque * -1.0f, ForwardVector.X * Torque, 0.0f);

		// Torque��^���ĉ�������
		Sphere->AddTorqueInRadians(TorqueVector, TEXT("None"), true);
	}
}
// No Copyright.

#include "Character/FPSPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Combat/FPSCombatComponent.h"

AFPSPlayerCharacter::AFPSPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
	
	GetCapsuleComponent()->SetCapsuleHalfHeight(90.f);
	GetCapsuleComponent()->SetCapsuleRadius(35.f);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 0.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 25.f;
	SpringArm->CameraLagMaxDistance = 5.f;
	SpringArm->bUseCameraLagSubstepping = true;
	SpringArm->CameraLagMaxTimeStep = 0.016f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = true;
	SpringArm->bDoCollisionTest = false;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	
	PlayerMesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh1P"));
	PlayerMesh1P->SetupAttachment(FollowCamera);
	PlayerMesh1P->SetOnlyOwnerSee(true);
	PlayerMesh1P->SetOwnerNoSee(false);
	PlayerMesh1P->SetCastShadow(false);
	PlayerMesh1P->SetReceivesDecals(false);
	PlayerMesh1P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	PlayerMesh1P->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	
	GetMesh()->SetOnlyOwnerSee(false);
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->SetCastShadow(true);
	GetMesh()->SetReceivesDecals(false);
	
	GetCharacterMovement()->MovementState.bCanCrouch = true;
	
	Combat = CreateDefaultSubobject<UFPSCombatComponent>(TEXT("CombatComponent"));
	Combat->SetIsReplicated(true);
}

void AFPSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

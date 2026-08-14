// No Copyright.

#include "Character/FPSPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Combat/FPSCombatComponent.h"
#include "EnhancedInput/FPSPlayerInputComponent.h"
#include "EnhancedInput/FPSPlayerInputDataAsset.h"
#include "Player/FPSPlayerController.h"
#include "Weapon/FPSWeaponDataAsset.h"

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
	
	DefaultFOV = 90.f;
}

void AFPSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FollowCamera->SetFieldOfView(DefaultFOV);
}

void AFPSPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	Combat->SpawnInventory();
}

void AFPSPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSPlayerCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Combat->DestroyInventory();
	
	Super::EndPlay(EndPlayReason);
}

void AFPSPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UFPSPlayerInputComponent* FPSPlayerInputComponent = CastChecked<UFPSPlayerInputComponent>(PlayerInputComponent);
	
	const AFPSPlayerController* FPSPlayerController = Cast<AFPSPlayerController>(GetController());
	if (!IsValid(FPSPlayerController)) return;
	
	const UFPSPlayerInputDataAsset* PlayerInputDataAsset = FPSPlayerController->GetPlayerInputDataAsset();
	check(PlayerInputDataAsset);
	
	check(PlayerInputDataAsset->CycleWeaponAction);
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->CycleWeaponAction, ETriggerEvent::Started,
		this, &AFPSPlayerCharacter::Input_CycleWeapon);
	
	check(PlayerInputDataAsset->FireWeaponAction);
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->FireWeaponAction, ETriggerEvent::Started,
		this, &AFPSPlayerCharacter::Input_FireWeaponPressed);
	
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->FireWeaponAction, ETriggerEvent::Completed,
		this, &AFPSPlayerCharacter::Input_FireWeaponReleased);
	
	check(PlayerInputDataAsset->ReloadWeaponAction);
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->ReloadWeaponAction, ETriggerEvent::Started,
		this, &AFPSPlayerCharacter::Input_ReloadWeapon);
	
	check(PlayerInputDataAsset->AimWeaponAction);
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->AimWeaponAction, ETriggerEvent::Started,
		this, &AFPSPlayerCharacter::Input_AimWeaponPressed);
	
	FPSPlayerInputComponent->BindAction(
		PlayerInputDataAsset->AimWeaponAction, ETriggerEvent::Completed,
		this, &AFPSPlayerCharacter::Input_AimWeaponReleased);
}

void AFPSPlayerCharacter::Input_CycleWeapon()
{
	Combat->Initiate_CycleWeapon();
}

void AFPSPlayerCharacter::Input_FireWeaponPressed()
{
	Combat->Initiate_FireWeaponPressed();
}

void AFPSPlayerCharacter::Input_FireWeaponReleased()
{
	Combat->Initiate_FireWeaponReleased();
}

void AFPSPlayerCharacter::Input_ReloadWeapon()
{
	Combat->Initiate_ReloadWeapon();
}

void AFPSPlayerCharacter::Input_AimWeaponPressed()
{
	Combat->Initiate_AimWeaponPressed();
	OnAimWeapon(true);
}

void AFPSPlayerCharacter::Input_AimWeaponReleased()
{
	Combat->Initiate_AimWeaponReleased();
	OnAimWeapon(false);
}

FName AFPSPlayerCharacter::GetWeaponGripPoint_Implementation(const FGameplayTag& WeaponType) const
{
	const UFPSWeaponDataAsset* WeaponDataAsset = Combat->GetWeaponDataAsset();
	check(WeaponDataAsset);
	return WeaponDataAsset->WeaponGripPoints.FindChecked(WeaponType);
}

USkeletalMeshComponent* AFPSPlayerCharacter::GetPlayerMesh1P_Implementation() const
{
	return PlayerMesh1P;
}

USkeletalMeshComponent* AFPSPlayerCharacter::GetPlayerMesh3P_Implementation() const
{
	return GetMesh();
}

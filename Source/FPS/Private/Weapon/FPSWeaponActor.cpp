// No Copyright.

#include "Weapon/FPSWeaponActor.h"

#include "Combat/FPSCombatComponent.h"
#include "Interface/FPSPlayerInterface.h"

AFPSWeaponActor::AFPSWeaponActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	bNetUseOwnerRelevancy = true;
	
	WeaponMesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh1P"));
	SetRootComponent(WeaponMesh1P);
	WeaponMesh1P->SetCastShadow(false);
	WeaponMesh1P->SetReceivesDecals(false);
	WeaponMesh1P->SetHiddenInGame(true);
	WeaponMesh1P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	
	WeaponMesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh3P"));
	WeaponMesh3P->SetupAttachment(GetRootComponent());
	WeaponMesh3P->SetCastShadow(true);
	WeaponMesh3P->SetReceivesDecals(false);
	WeaponMesh3P->SetHiddenInGame(true);
	WeaponMesh3P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
}

void AFPSWeaponActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSWeaponActor::AttachWeaponToOwningPawn()
{
	const APawn* OwningPawn = GetInstigator();
	if (!IsValid(OwningPawn) || !OwningPawn->Implements<UFPSPlayerInterface>()) return;
	
	SetWeaponMeshVisibility(OwningPawn);
	
	const FName WeaponGripPoint = IFPSPlayerInterface::Execute_GetWeaponGripPoint(OwningPawn, WeaponType);
	USkeletalMeshComponent* PlayerMesh1P = IFPSPlayerInterface::Execute_GetPlayerMesh1P(OwningPawn);
	USkeletalMeshComponent* PlayerMesh3P = IFPSPlayerInterface::Execute_GetPlayerMesh3P(OwningPawn);
	
	WeaponMesh1P->AttachToComponent(PlayerMesh1P, FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponGripPoint);
	WeaponMesh3P->AttachToComponent(PlayerMesh3P, FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponGripPoint);
}

void AFPSWeaponActor::OnRep_Instigator()
{
	Super::OnRep_Instigator();
	
	const APawn* OwningPawn = GetInstigator();
	if (!IsValid(OwningPawn)) return;
	
	const UFPSCombatComponent* Combat = OwningPawn->FindComponentByClass<UFPSCombatComponent>();
	if (!IsValid(Combat)) return;
 
	if (Combat->GetCurrentEquippedWeapon() == this)
	{
		AttachWeaponToOwningPawn();
	}
}

void AFPSWeaponActor::SetWeaponMeshVisibility(const APawn* OwningPawn)
{
	if (OwningPawn->IsLocallyControlled())
	{
		WeaponMesh1P->SetHiddenInGame(false);
		WeaponMesh3P->SetHiddenInGame(true);
	}
	else
	{
		WeaponMesh1P->SetHiddenInGame(true);
		WeaponMesh3P->SetHiddenInGame(false);
	}
}

// No Copyright.

#include "Combat/FPSCombatComponent.h"
#include "Weapon/FPSWeaponActor.h"
#include "Net/UnrealNetwork.h"

UFPSCombatComponent::UFPSCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UFPSCombatComponent::TickComponent(
	float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UFPSCombatComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UFPSCombatComponent, Inventory);
	DOREPLIFETIME(UFPSCombatComponent, CurrentEquippedWeapon);
}

void UFPSCombatComponent::OnRep_CurrentEquippedWeapon(AFPSWeaponActor* OldEquippedWeapon)
{
	if (!IsValid(CurrentEquippedWeapon)) return;
	CurrentEquippedWeapon->AttachWeaponToOwningPawn();
}

void UFPSCombatComponent::Initiate_CycleWeapon()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_CycleWeapon"), false);
}

void UFPSCombatComponent::Initiate_FireWeaponPressed()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_FireWeaponPressed"), false);
}

void UFPSCombatComponent::Initiate_FireWeaponReleased()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_FireWeaponReleased"), false);
}

void UFPSCombatComponent::Initiate_ReloadWeapon()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_ReloadWeapon"), false);
}

void UFPSCombatComponent::Initiate_AimWeaponPressed()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_AimWeaponPressed"), false);
}

void UFPSCombatComponent::Initiate_AimWeaponReleased()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_AimWeaponReleased"), false);
}

void UFPSCombatComponent::SpawnInventory()
{
	const AActor* OwningActor = GetOwner();
	if (!IsValid(OwningActor)) return;
	if (!OwningActor->HasAuthority()) return;
	
	for (const TSubclassOf<AFPSWeaponActor>& WeaponClass : DefaultWeaponClasses)
	{
		AFPSWeaponActor* NewWeapon = SpawnWeapon(WeaponClass);
		Inventory.AddUnique(NewWeapon);
	}
	
	if (Inventory.IsEmpty()) return;
	EquipWeapon(Inventory[0]);
}

void UFPSCombatComponent::DestroyInventory()
{
	for (AFPSWeaponActor* Weapon : Inventory)
	{
		if (!IsValid(Weapon)) continue;
		Weapon->Destroy();
	}
}

AFPSWeaponActor* UFPSCombatComponent::SpawnWeapon(const TSubclassOf<AFPSWeaponActor>& WeaponClassToSpawn) const
{
	AActor* OwningActor = GetOwner();
	if (!IsValid(OwningActor)) return nullptr;
	if (!OwningActor->HasAuthority()) return nullptr;
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = OwningActor;
	SpawnParams.Instigator = Cast<APawn>(OwningActor);
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	return GetWorld()->SpawnActor<AFPSWeaponActor>(WeaponClassToSpawn, SpawnParams);
}

void UFPSCombatComponent::EquipWeapon(AFPSWeaponActor* Weapon)
{
	CurrentEquippedWeapon = Weapon;
	CurrentEquippedWeapon->AttachWeaponToOwningPawn();
}

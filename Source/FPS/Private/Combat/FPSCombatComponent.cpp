// No Copyright.

#include "Combat/FPSCombatComponent.h"

UFPSCombatComponent::UFPSCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UFPSCombatComponent::TickComponent(
	float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
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

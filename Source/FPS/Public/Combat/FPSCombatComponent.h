// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FPSCombatComponent.generated.h"

class AFPSWeaponActor;
class UFPSWeaponDataAsset;
/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_API UFPSCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFPSCombatComponent();
	
	virtual void TickComponent(
		float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	FORCEINLINE UFPSWeaponDataAsset* GetWeaponDataAsset() const { return WeaponDataAsset; }
	FORCEINLINE AFPSWeaponActor* GetCurrentEquippedWeapon() const { return CurrentEquippedWeapon; }
	
	void SpawnInventory();
	void DestroyInventory();
	void EquipWeapon(AFPSWeaponActor* Weapon);
	
	void Initiate_CycleWeapon();
	
	void Initiate_FireWeaponPressed();
	void Initiate_FireWeaponReleased();
	
	void Initiate_ReloadWeapon();
	
	void Initiate_AimWeaponPressed();
	void Initiate_AimWeaponReleased();

protected:
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Weapon")
	TObjectPtr<UFPSWeaponDataAsset> WeaponDataAsset;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Weapon")
	TArray<TSubclassOf<AFPSWeaponActor>> DefaultWeaponClasses;
	
	UPROPERTY(Transient, Replicated)
	TArray<AFPSWeaponActor*> Inventory;
	
	UPROPERTY(Transient, ReplicatedUsing = OnRep_CurrentEquippedWeapon)
	TObjectPtr<AFPSWeaponActor> CurrentEquippedWeapon;
	
	UFUNCTION()
	void OnRep_CurrentEquippedWeapon(AFPSWeaponActor* OldEquippedWeapon);
	
	AFPSWeaponActor* SpawnWeapon(const TSubclassOf<AFPSWeaponActor>& WeaponClassToSpawn) const;
};

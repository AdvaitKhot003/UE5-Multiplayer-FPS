// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FPSCombatComponent.generated.h"

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
	
	FORCEINLINE UFPSWeaponDataAsset* GetWeaponDataAsset() const { return WeaponDataAsset; }
	
	void Initiate_CycleWeapon();
	
	void Initiate_FireWeaponPressed();
	void Initiate_FireWeaponReleased();
	
	void Initiate_ReloadWeapon();
	
	void Initiate_AimWeaponPressed();
	void Initiate_AimWeaponReleased();

protected:
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Weapon")
	UFPSWeaponDataAsset* WeaponDataAsset;
};

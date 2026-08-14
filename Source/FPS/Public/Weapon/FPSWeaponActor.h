// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "GameplayTag/FPSGameplayTags.h"
#include "FPSWeaponActor.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API AFPSWeaponActor : public AActor
{
	GENERATED_BODY()

public:
	AFPSWeaponActor();
	
	virtual void OnRep_Instigator() override;
	
	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh1P() const { return WeaponMesh1P; }
	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh3P() const { return WeaponMesh3P; }
	
	FORCEINLINE FGameplayTag GetWeaponType() const { return WeaponType; }
	
	void AttachWeaponToOwningPawn();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FPS|Combat")
	float AimWeaponFOV;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FPS|Weapon", meta = (Categories = "Weapon.WeaponType"))
	FGameplayTag WeaponType = WeaponTags::WeaponType_None;
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> WeaponMesh1P;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> WeaponMesh3P;
	
	void SetWeaponMeshVisibility(const APawn* OwningPawn);
};

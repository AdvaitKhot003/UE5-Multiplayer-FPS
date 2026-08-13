// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "FPSWeaponDataAsset.generated.h"

class UBlendSpace;
class UAnimSequence;

USTRUCT(BlueprintType)
struct FPlayerAnimSet
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Animation.AnimSequence"))
	TMap<FGameplayTag, TObjectPtr<UAnimSequence>> AnimationSequences;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Animation.BlendSpace"))
	TMap<FGameplayTag, TObjectPtr<UBlendSpace>> BlendSpaces;
};

/**
 * 
 */
UCLASS()
class FPS_API UFPSWeaponDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Weapon", meta = (Categories = "Weapon.WeaponType"))
	TMap<FGameplayTag, FName> WeaponGripPoints;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FPS|Animation", meta = (Categories = "Weapon.WeaponType"))
	TMap<FGameplayTag, FPlayerAnimSet> PlayerAnimSet1P;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FPS|Animation", meta = (Categories = "Weapon.WeaponType"))
	TMap<FGameplayTag, FPlayerAnimSet> PlayerAnimSet3P;
};

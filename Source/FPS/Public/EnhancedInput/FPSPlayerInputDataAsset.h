// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FPSPlayerInputDataAsset.generated.h"

class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class FPS_API UFPSPlayerInputDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	/** Input Mapping Context */
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IMC")
	TObjectPtr<UInputMappingContext> FPSMappingContext;
	
	/** Movement Input Actions */
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IA|Movement")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IA|Movement")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IA|Movement")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IA|Movement")
	TObjectPtr<UInputAction> CrouchAction;
	
	/** Combat Input Actions */
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IA|Combat")
	TObjectPtr<UInputAction> CycleWeaponAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IA|Combat")
	TObjectPtr<UInputAction> FireWeaponAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IA|Combat")
	TObjectPtr<UInputAction> ReloadWeaponAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|IA|Combat")
	TObjectPtr<UInputAction> AimWeaponAction;
};

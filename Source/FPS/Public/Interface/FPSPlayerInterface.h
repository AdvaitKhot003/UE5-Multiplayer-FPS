// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "FPSPlayerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UFPSPlayerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPS_API IFPSPlayerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FName GetWeaponGripPoint(const FGameplayTag& WeaponType) const;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	USkeletalMeshComponent* GetPlayerMesh1P() const;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	USkeletalMeshComponent* GetPlayerMesh3P() const;
};

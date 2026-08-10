// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSPlayerCharacter.generated.h"

class UFPSCombatComponent;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class FPS_API AFPSPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFPSPlayerCharacter();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> FollowCamera;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> PlayerMesh1P;
	
	UPROPERTY(VisibleAnywhere, Category = "FPS|Combat")
	TObjectPtr<UFPSCombatComponent> Combat;
	
	void Input_CycleWeapon();
	
	void Input_FireWeaponPressed();
	void Input_FireWeaponReleased();
	
	void Input_ReloadWeapon();
	
	void Input_AimWeaponPressed();
	void Input_AimWeaponReleased();
};

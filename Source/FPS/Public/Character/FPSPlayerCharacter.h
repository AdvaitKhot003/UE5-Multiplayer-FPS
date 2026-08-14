// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/FPSPlayerInterface.h"
#include "FPSPlayerCharacter.generated.h"

class UFPSCombatComponent;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class FPS_API AFPSPlayerCharacter : public ACharacter, public IFPSPlayerInterface
{
	GENERATED_BODY()

public:
	AFPSPlayerCharacter();
	
	virtual void BeginPlay() override;
	
	virtual void PossessedBy(AController* NewController) override;
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
#pragma region Player Interface
	virtual FName GetWeaponGripPoint_Implementation(const FGameplayTag& WeaponType) const override;
	
	virtual USkeletalMeshComponent* GetPlayerMesh1P_Implementation() const override;
	virtual USkeletalMeshComponent* GetPlayerMesh3P_Implementation() const override;
#pragma endregion
	
	UFUNCTION(BlueprintCallable)
	float GetMappedPitchAimRotation() const;
	
	UPROPERTY(BlueprintReadOnly, Category = "FPS|FABRIK")
	FTransform FABRIKSocketTransform;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FPS|Camera")
	TObjectPtr<USpringArmComponent> SpringArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FPS|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FPS|Mesh")
	TObjectPtr<USkeletalMeshComponent> PlayerMesh1P;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FPS|Combat")
	TObjectPtr<UFPSCombatComponent> Combat;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FPS|Combat")
	float DefaultFOV;
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnAimWeapon(bool bIsAiming);
	
private:
	void Input_CycleWeapon();
	
	void Input_FireWeaponPressed();
	void Input_FireWeaponReleased();
	
	void Input_ReloadWeapon();
	
	void Input_AimWeaponPressed();
	void Input_AimWeaponReleased();
	
	void CalculateFABRIKSocketTransform();
};

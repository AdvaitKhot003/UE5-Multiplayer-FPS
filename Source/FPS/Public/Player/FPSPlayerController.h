// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPSPlayerController.generated.h"

struct FInputActionValue;
class UFPSPlayerInputDataAsset;
/**
 * 
 */
UCLASS()
class FPS_API AFPSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFPSPlayerController();
	
	FORCEINLINE UFPSPlayerInputDataAsset* GetPlayerInputDataAsset() const { return PlayerInputDataAsset; }
	
protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input")
	TObjectPtr<UFPSPlayerInputDataAsset> PlayerInputDataAsset;
	
	void Input_Look(const FInputActionValue& InputActionValue);
	void Input_Move(const FInputActionValue& InputActionValue);
	
	void Input_JumpPressed();
	void Input_JumpReleased();
	
	void Input_CrouchPressed();
	void Input_CrouchReleased();
};

// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "FPSPlayerInputComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_API UFPSPlayerInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UFPSPlayerInputComponent();
};

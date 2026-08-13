// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace WeaponTags
{
#pragma region Weapon Types
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WeaponType_None);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WeaponType_Pistol);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WeaponType_Rifle);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WeaponType_Shotgun);
#pragma endregion 
}

namespace AnimationTags
{
#pragma region AnimSequences
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Animation_Idle);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Animation_AimIdle);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Animation_CrouchIdle);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Animation_Sprint);
#pragma endregion

#pragma region BlendSpaces
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlendSpace_AimOffset_Hip);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlendSpace_AimOffset_Aim);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlendSpace_Strafe_Standing);
	FPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlendSpace_Strafe_Crouching);
#pragma endregion
}

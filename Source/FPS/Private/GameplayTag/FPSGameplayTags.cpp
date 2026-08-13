// No Copyright.

#include "GameplayTag/FPSGameplayTags.h"

namespace WeaponTags
{
#pragma region Weapon Types
	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		WeaponType_None,
		"Weapon.WeaponType.None",
		"Weapon Type : None"
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		WeaponType_Pistol,
		"Weapon.WeaponType.Pistol",
		"Weapon Type : Pistol"
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		WeaponType_Rifle,
		"Weapon.WeaponType.Rifle",
		"Weapon Type : Rifle"
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		WeaponType_Shotgun,
		"Weapon.WeaponType.Shotgun",
		"Weapon Type : Shotgun"
	);
#pragma endregion 
}

namespace AnimationTags
{
#pragma region AnimSequences
	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		Animation_Idle,
		"Animation.AnimSequence.Idle",
		"Anim Sequence : Idle"
	);

	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		Animation_AimIdle,
		"Animation.AnimSequence.AimIdle",
		"Anim Sequence : Aim Idle"
	);

	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		Animation_CrouchIdle,
		"Animation.AnimSequence.CrouchIdle",
		"Anim Sequence : Crouch Idle"
	);

	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		Animation_Sprint,
		"Animation.AnimSequence.Sprint",
		"Anim Sequence : Sprint"
	);
#pragma endregion

#pragma region BlendSpaces
	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		BlendSpace_AimOffset_Hip,
		"Animation.BlendSpace.AimOffset.Hip",
		"BlendSpace : Aim Offset Hip"
	);

	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		BlendSpace_AimOffset_Aim,
		"Animation.BlendSpace.AimOffset.Aim",
		"BlendSpace : Aim Offset Aim"
	);

	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		BlendSpace_Strafe_Standing,
		"Animation.BlendSpace.Strafe.Standing",
		"BlendSpace : Strafe Standing"
	);

	UE_DEFINE_GAMEPLAY_TAG_COMMENT
	(
		BlendSpace_Strafe_Crouching,
		"Animation.BlendSpace.Strafe.Crouching",
		"BlendSpace : Strafe Crouching"
	);
#pragma endregion
}

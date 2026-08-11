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

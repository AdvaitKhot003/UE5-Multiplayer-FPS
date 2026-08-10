// No Copyright.

#include "Combat/FPSCombatComponent.h"

UFPSCombatComponent::UFPSCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UFPSCombatComponent::TickComponent(
	float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

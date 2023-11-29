

#include "TestClass.h"
#include "Actors/PlayerActorClass.h"
#include "Actors/ObstacleBase.h"

bool TestClass::CheckIfBehind(TObjectPtr<APlayerActorClass> player, TObjectPtr<AObstacleBase> target)
{
	const FVector targetLocation = target->GetActorLocation();
	const FVector localLocation = player->GetActorTransform().InverseTransformPosition(targetLocation);

	if (localLocation.X < 0) { return true; }

	return false;
}

bool TestClass::CheckIfOverlapping(TObjectPtr<APlayerActorClass> player, TObjectPtr<AObstacleBase> target)
{
	FVector playerMax = player->GetAABB_Max();
	FVector playerMin = player->GetAABB_Min();
	FVector targetMax = target->GetAABB_Max();
	FVector targetMin = target->GetAABB_Min();
	
	if (playerMax.X < targetMin.X || targetMax.X < playerMin.X)
	{
		return false;
	}
	if (playerMax.Y < targetMin.Y || targetMax.Y < playerMin.Y)
	{
		return false;
	}
	if (playerMax.Z < targetMin.Z || targetMax.Z < playerMin.Z)
	{
		return false;
	}

	return true;
}
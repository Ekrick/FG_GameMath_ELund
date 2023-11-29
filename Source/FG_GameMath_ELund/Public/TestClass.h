
#pragma once

#include "CoreMinimal.h"

class APlayerActorClass;
class AObstacleBase;

class FG_GAMEMATH_ELUND_API TestClass
{
public:
	UFUNCTION()
	static bool CheckIfBehind(TObjectPtr<APlayerActorClass> player, TObjectPtr<AObstacleBase> target);
	UFUNCTION()
	static bool CheckIfOverlapping(TObjectPtr<APlayerActorClass> player, TObjectPtr<AObstacleBase> target);
};

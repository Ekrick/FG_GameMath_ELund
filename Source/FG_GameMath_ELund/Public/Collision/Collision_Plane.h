
#pragma once

#include "CoreMinimal.h"
#include "Collision_Base.h"
#include "Collision_Plane.generated.h"

UCLASS()
class FG_GAMEMATH_ELUND_API ACollision_Plane : public ACollision_Base
{
	GENERATED_BODY()
	
public:	

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

};

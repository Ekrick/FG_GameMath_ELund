
#pragma once

#include "CoreMinimal.h"
#include "Collision_Base.h"
#include "Collision_Sphere.generated.h"

class ACollision_AABB;

UCLASS()
class FG_GAMEMATH_ELUND_API ACollision_Sphere : public ACollision_Base
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	float GetRadius() const { return fRadius; }
	

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "SphereCollision", meta=(AllowPrivateAccess = "true"))
	float fRadius = 100.f;

	void CalculateMovement(float DeltaTime);
	
};

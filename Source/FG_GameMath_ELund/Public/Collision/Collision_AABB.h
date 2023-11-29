
#pragma once

#include "CoreMinimal.h"
#include "Collision_Base.h"
#include "Collision_AABB.generated.h"

class ACollision_Sphere;

UCLASS()
class FG_GAMEMATH_ELUND_API ACollision_AABB : public ACollision_Base
{
	GENERATED_BODY()
	
public:	
	UFUNCTION()
	FVector GetAABB_Max() { return AABBMax; }
	UFUNCTION()
	FVector GetAABB_Min() { return AABBMin; }

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AxisAlignedBoundingBox", meta=(AllowPrivateAccess = "true"))
	float fAABB_Width = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AxisAlignedBoundingBox", meta=(AllowPrivateAccess = "true"))
	float fAABB_Height = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AxisAlignedBoundingBox", meta=(AllowPrivateAccess = "true"))
	float fAABB_Depth = 100.f;

	UPROPERTY(VisibleAnywhere, Category= "AxisAlignedBoundingBox")
	FVector AABBMax;
	UPROPERTY(VisibleAnywhere, Category= "AxisAlignedBoundingBox")
	FVector AABBMin;

	void UpdateAABB();

};

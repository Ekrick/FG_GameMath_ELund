
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleBase.generated.h"

class APlayerActorClass;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FResetObstacle);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOverlapPlayer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPassedPlayer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeactivated, AObstacleBase*, obstacle);
UCLASS()
class FG_GAMEMATH_ELUND_API AObstacleBase : public AActor
{
	GENERATED_BODY()

public:
	AObstacleBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "StaticMeshComponent")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	UPROPERTY(BlueprintAssignable)
	FResetObstacle OnObstacleReset;
	UPROPERTY(BlueprintAssignable)
	FOverlapPlayer OnPlayerOverlap;
	UPROPERTY(BlueprintAssignable)
	FPassedPlayer OnPlayerPassed;
	UPROPERTY(BlueprintAssignable)
	FDeactivated OnDeactivation;
	
	UFUNCTION()
	void SetSpeedAndActivate(float Speed) { fSpeed = Speed; bActive = true; OnObstacleReset.Broadcast(); }
	UFUNCTION()
	void Deactivate() { fSpeed = 0; bActive = false; SetActorLocation(FVector(0,0,-1000));  }
	UFUNCTION()
	void CheckPosition();
	UFUNCTION()
	void CheckHit();

	UFUNCTION()
	FVector GetAABB_Max() { return AABBMax; }
	UFUNCTION()
	FVector GetAABB_Min() { return AABBMin; }
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	bool bActive = false;
	UPROPERTY()
	bool bOverlapping = false;
	UPROPERTY()
	int fSpeed = 0;

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
	
	UPROPERTY()
	TObjectPtr<APlayerActorClass> PlayerCharacter;

	UFUNCTION()
	void UpdateAABB();
	UFUNCTION()
	void MoveObstacle(float DeltaTime);
	

};

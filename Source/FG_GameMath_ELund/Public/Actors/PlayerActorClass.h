
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerActorClass.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerFire);

UCLASS()
class FG_GAMEMATH_ELUND_API APlayerActorClass : public APawn
{
	GENERATED_BODY()

public:
	APlayerActorClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "CameraSettings")
	TObjectPtr<UCameraComponent> Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "CameraSettings")
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "StaticMeshComponent")
	TObjectPtr<UStaticMeshComponent> StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MaterialInstance")
	TObjectPtr<UMaterialInstanceDynamic> MaterialInstance;

	UPROPERTY(BlueprintAssignable)
	FPlayerFire OnFireAction;

	UFUNCTION(BlueprintCallable, Category = "MaterialInstnace")
	void UpdateMaterial(FVector colorVector);
	
	UFUNCTION()
	void MovePlayer(float DeltaTime);

	UFUNCTION()
	void Fire();

	UFUNCTION()
	int GetPositionIndex() { return iPositionIndex; }

	UFUNCTION()
	void ChangePositionIndex(bool add);

	UFUNCTION()
	FVector GetAABB_Max() { return AABBMax; }
	UFUNCTION()
	FVector GetAABB_Min() { return AABBMin; }
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "GameplaySettings", meta=(AllowPrivateAccess = "true"))
	float fLerpDuration = 1.f;
	UPROPERTY()
	float fTime = 0.f;
	UPROPERTY()
	float T = 0.f;
	UPROPERTY()
	bool bMoving = false;
	UPROPERTY()
	FVector PreviousPosition;
	UPROPERTY()
	FVector TargetPosition;
	
	UPROPERTY()
	TArray<FVector> LaneArray;

	UPROPERTY()
	int8 iPositionIndex = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Lanes", meta=(AllowPrivateAccess = "true"))
	FVector LeftLane = FVector(0 , -1000, 0);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Lanes", meta=(AllowPrivateAccess = "true"))
	FVector MiddleLane = FVector(0 , 0, 0);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Lanes", meta=(AllowPrivateAccess = "true"))
	FVector RightLane = FVector(0 , 1000, 0);

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

	UFUNCTION()
	void UpdateAABB();

};

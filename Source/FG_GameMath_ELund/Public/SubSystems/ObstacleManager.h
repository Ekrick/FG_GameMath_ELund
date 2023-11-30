
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ObstacleManager.generated.h"


class AObstacleBase;
class AObstaclePool;

UCLASS()
class FG_GAMEMATH_ELUND_API UObstacleManager : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetPool(AObstaclePool* pool) { ObstaclePool = pool; }
	
protected:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void Tick(float DeltaTime) override;
	
	virtual TStatId GetStatId() const override
	{
		return  GetStatID();
	}

private:
	UPROPERTY()
	TArray<int> NoiseArray;
	UPROPERTY()
	int iNoiseArraySize = 100;
	UPROPERTY()
	float fNoiseConstant = 10.f;
	UPROPERTY()
	int iNoiseIndex = 0;
	
	UPROPERTY()
	int iSpawnInterval = 2;
	UPROPERTY()
	float fTimer = 0;
	UPROPERTY()
	float fObstacleSpeed = 1000;
	
	UPROPERTY()
	FVector LeftLane = FVector(3000 , -1000, 0);
	UPROPERTY()
	FVector MiddleLane = FVector(3000 , 0, 0);
	UPROPERTY()
	FVector RightLane = FVector(3000 , 1000, 0);
		
	UPROPERTY()
	TArray<FVector> LaneArray;
	UPROPERTY()
	TObjectPtr<AObstaclePool> ObstaclePool;
	UPROPERTY()
	TArray<TObjectPtr<AObstacleBase>> ActiveObstacles;

	UFUNCTION()
	void GenerateNoise();
	
	UFUNCTION()
	void SpawningObstacles();
	
	UFUNCTION()
	void SpawnTimer(float DeltaTime);
};

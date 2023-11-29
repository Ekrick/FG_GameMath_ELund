

#include "SubSystems/ObstacleManager.h"

#include "Actors/ObstacleBase.h"
#include "Algo/RandomShuffle.h"
#include "SubSystems/ObstaclePool.h"


void UObstacleManager::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	LaneArray.Add(RightLane);
	LaneArray.Add(MiddleLane);
	LaneArray.Add(LeftLane);
}

void UObstacleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnTimer(DeltaTime);
}

void UObstacleManager::SpawningObstacles()
{
	if (!ObstaclePool) { return; }

	int iRandomIndex = FMath::RandRange(0,2);

	TObjectPtr<AObstacleBase> obstacle = ObstaclePool->Pool.Pop();
	ActiveObstacles.Add(obstacle);
	obstacle->SetSpeedAndActivate(fObstacleSpeed);
	obstacle->SetActorLocation(LaneArray[iRandomIndex]);
}

void UObstacleManager::SpawnTimer(float DeltaTime)
{
	fTimer += DeltaTime;
	if (fTimer >= iSpawnInterval)
	{
		fTimer = 0;
		SpawningObstacles();
	}
}



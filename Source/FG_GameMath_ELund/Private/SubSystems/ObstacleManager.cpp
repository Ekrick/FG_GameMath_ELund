

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

	GenerateNoise();
}

void UObstacleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnTimer(DeltaTime);
}

void UObstacleManager::GenerateNoise()
{
	NoiseArray.SetNum(iNoiseArraySize);

	//create randomized array of ints (0, 1, or 2)
	for (int i = 0 ; i < iNoiseArraySize ; i++)
	{
		float noiseValue = FMath::PerlinNoise1D((i * i) / fNoiseConstant);
		int randomInt = FMath::RoundToInt(noiseValue) +1;
		NoiseArray[i] = randomInt;
	}
}

void UObstacleManager::SpawningObstacles()
{
	if (!ObstaclePool || ObstaclePool->IsEmpty()) { return; }

	//get a spawn point from the noise array
	int spawnIndex = NoiseArray[iNoiseIndex];
	iNoiseIndex++;
	if (iNoiseIndex > iNoiseArraySize)
	{
		iNoiseIndex = 0;
	}

	TObjectPtr<AObstacleBase> obstacle = ObstaclePool->Pool.Pop();
	ActiveObstacles.Add(obstacle);
	obstacle->SetSpeedAndActivate(fObstacleSpeed);
	obstacle->SetActorLocation(LaneArray[spawnIndex]);
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




#include "SubSystems/ObstaclePool.h"
#include "Actors/ObstacleBase.h"
#include "SubSystems/ObstacleManager.h"

void AObstaclePool::BeginPlay()
{
	Super::BeginPlay();
	
	TObjectPtr<UObstacleManager> manager = GetWorld()->GetSubsystem<UObstacleManager>();
	if (manager)
	{
		manager->SetPool(this);
	}

	for (int i = 0; i < iPoolSize; i++)
	{
		TObjectPtr<AObstacleBase> Spawned = GetWorld()->SpawnActor<AObstacleBase>(ObstacleToSpawn, FVector(1000, 0, -1000), FRotator::ZeroRotator);
		Pool.Add(Spawned);
	}

}

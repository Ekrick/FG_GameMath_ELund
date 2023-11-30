
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstaclePool.generated.h"

class AObstacleBase;

UCLASS()
class FG_GAMEMATH_ELUND_API AObstaclePool : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Pool Settings", meta=(AllowPrivateAccess = "true"))
	TSubclassOf<AObstacleBase> ObstacleToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Pool Settings", meta=(AllowPrivateAccess = "true"))
	int iPoolSize = 100;
	
	UPROPERTY()
	TArray<TObjectPtr<AObstacleBase>> Pool;

	UFUNCTION()
	bool IsEmpty() { return Pool.IsEmpty(); }

protected:
	virtual void BeginPlay() override;
	
};

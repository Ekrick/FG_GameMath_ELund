
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collision_Base.generated.h"

class ACollision_Demonstration_Manager;

UCLASS()
class FG_GAMEMATH_ELUND_API ACollision_Base : public AActor
{
	GENERATED_BODY()
	
public:
	ACollision_Base();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "CollisionTest", meta=(AllowPrivateAccess = "true"))
	FVector MovementVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "CollisionTest", meta=(AllowPrivateAccess = "true"))
	float fSpeed = 100;
	
	void SetManager(ACollision_Demonstration_Manager* manager) { Manager = manager; }

protected:
	TObjectPtr<ACollision_Demonstration_Manager> Manager;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

};

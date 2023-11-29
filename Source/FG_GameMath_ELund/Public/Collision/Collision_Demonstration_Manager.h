
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collision_Demonstration_Manager.generated.h"

class ACollision_Base;

UCLASS

()
class FG_GAMEMATH_ELUND_API ACollision_Demonstration_Manager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACollision_Demonstration_Manager();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:	
	void SetupExample();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "ExampleSettings", meta=(AllowPrivateAccess = "true"))
	TSubclassOf<ACollision_Base> ActorToSpawn1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "ExampleSettings", meta=(AllowPrivateAccess = "true"))
	TSubclassOf<ACollision_Base> ActorToSpawn2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "ExampleSettings", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<ACollision_Base> ExampleActor1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "ExampleSettings", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<ACollision_Base> ExampleActor2;

	void CheckCollision();

};


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameActorBase.generated.h"

UCLASS()
class FG_GAMEMATH_ELUND_API AGameActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AGameActorBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "StaticMeshComponent")
	TObjectPtr<UStaticMeshComponent> StaticMesh;

};

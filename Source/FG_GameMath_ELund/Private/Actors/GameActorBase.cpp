

#include "Actors/GameActorBase.h"

AGameActorBase::AGameActorBase()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));
	SetRootComponent(StaticMesh);
}


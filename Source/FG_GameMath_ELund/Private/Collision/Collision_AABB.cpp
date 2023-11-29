

#include "Collision/Collision_AABB.h"

void ACollision_AABB::BeginPlay()
{
	Super::BeginPlay();
}

void ACollision_AABB::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAABB();
}

void ACollision_AABB::UpdateAABB()
{
	AABBMax = GetActorLocation() + FVector(fAABB_Depth/2, fAABB_Width/2, fAABB_Height/2);
	AABBMin = GetActorLocation() - FVector(fAABB_Depth/2, fAABB_Width/2, fAABB_Height/2);
}




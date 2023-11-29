

#include "Collision/Collision_Sphere.h"


void ACollision_Sphere::BeginPlay()
{
	Super::BeginPlay();
}

void ACollision_Sphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalculateMovement(DeltaTime);


}

void ACollision_Sphere::CalculateMovement(float DeltaTime)
{
	this->SetActorLocation(GetActorLocation() + MovementVector * fSpeed * DeltaTime);
}



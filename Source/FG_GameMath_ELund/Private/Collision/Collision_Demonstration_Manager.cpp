

#include "Collision/Collision_Demonstration_Manager.h"

#include "Collision/Collision_Base.h"
#include "Collision/Collision_Sphere.h"

ACollision_Demonstration_Manager::ACollision_Demonstration_Manager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACollision_Demonstration_Manager::BeginPlay()
{
	Super::BeginPlay();

	SetupExample();
}

void ACollision_Demonstration_Manager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckCollision();
}

void ACollision_Demonstration_Manager::SetupExample()
{
	ExampleActor1 = GetWorld()->SpawnActor<ACollision_Base>(ActorToSpawn1,  FVector(0, 1000, 500), FRotator::ZeroRotator);
	ExampleActor1->SetManager(this);
	ExampleActor1->MovementVector = GetActorLocation()-ExampleActor1->GetActorLocation();
	ExampleActor1->MovementVector.Normalize();
	
	ExampleActor2 = GetWorld()->SpawnActor<ACollision_Base>(ActorToSpawn2,  FVector(0, -1000, 500), FRotator::ZeroRotator);
	ExampleActor2->SetManager(this);
	ExampleActor2->MovementVector = GetActorLocation()-ExampleActor2->GetActorLocation();
	ExampleActor2->MovementVector.Normalize();
}

void ACollision_Demonstration_Manager::CheckCollision()
{
	//sphere sphere collision
	if(TObjectPtr<ACollision_Sphere> sphere1 = Cast<ACollision_Sphere>(ExampleActor1))
	{
		if (TObjectPtr<ACollision_Sphere> sphere2 = Cast<ACollision_Sphere>(ExampleActor2))
		{
			FVector distanceVector = sphere1->GetActorLocation() - sphere2->GetActorLocation();
			float distance = distanceVector.Length();

			if (distance <= sphere1->GetRadius() + sphere2->GetRadius())
			{
				FVector newMovement1 = sphere1->MovementVector + distanceVector.Normalize();
				newMovement1.Normalize();
				sphere1->MovementVector = newMovement1;
				
				FVector newMovement2 = sphere2->MovementVector - distanceVector.Normalize();
				newMovement2.Normalize();
				sphere2->MovementVector = newMovement2;
			}
		}
	}
	
}


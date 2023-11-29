

#include "Actors/ObstacleBase.h"
#include "TestClass.h"
#include "Actors/PlayerActorClass.h"

AObstacleBase::AObstacleBase()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(GetRootComponent());
}

void AObstacleBase::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<APlayerActorClass>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerCharacter)
	{
		PlayerCharacter->OnFireAction.AddDynamic(this, &AObstacleBase::CheckHit);
	}
	
}

void AObstacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveObstacle(DeltaTime);
	CheckPosition();
	UpdateAABB();
}

void AObstacleBase::MoveObstacle(float DeltaTime)
{
	this->SetActorLocation(GetActorLocation() + FVector(-fSpeed, 0, 0) * DeltaTime );
}

void AObstacleBase::CheckPosition()
{
	if (!bActive) { return; }
	
	if (!PlayerCharacter)
	{
		PlayerCharacter = Cast<APlayerActorClass>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (PlayerCharacter)
		{
			PlayerCharacter->OnFireAction.AddDynamic(this, &AObstacleBase::CheckHit);
		}
		return;
	}
	
	if (TestClass::CheckIfOverlapping(PlayerCharacter, this))
	{
		OnPlayerOverlap.Broadcast();
		bOverlapping = true;
		return;
	}
	
	if (TestClass::CheckIfBehind(PlayerCharacter, this))
	{
		bActive = false;
		bOverlapping = false;
		OnPlayerPassed.Broadcast();
	}
}

void AObstacleBase::CheckHit()
{
	if (bOverlapping)
	{
		Deactivate();
		OnDeactivation.Broadcast(this);
	}
}

void AObstacleBase::UpdateAABB()
{
	AABBMax = GetActorLocation() + FVector(fAABB_Depth/2, fAABB_Width/2, fAABB_Height);
	AABBMin = GetActorLocation() - FVector(fAABB_Depth/2, fAABB_Width/2, 0);
}

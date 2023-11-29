

#include "Actors/PlayerActorClass.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


APlayerActorClass::APlayerActorClass()
{
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));
	SetRootComponent(StaticMesh);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(StaticMesh);
	SpringArm->TargetArmLength = 500.0f;
	SpringArm->bUsePawnControlRotation = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

}

void APlayerActorClass::BeginPlay()
{
	Super::BeginPlay();

	LaneArray.Add(RightLane);
	LaneArray.Add(MiddleLane);
	LaneArray.Add(LeftLane);

	PreviousPosition = MiddleLane;
}

void APlayerActorClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAABB();

	MovePlayer(DeltaTime);
}


void APlayerActorClass::UpdateMaterial(FVector colorVector)
{
	MaterialInstance->SetVectorParameterValue("Parameter Name", colorVector);
}

void APlayerActorClass::MovePlayer(float DeltaTime)
{
	float distanceToTarget = (TargetPosition - GetActorLocation()).Length();
	if (distanceToTarget > 0.1f)
	{
		bMoving = true;
		
		//change T based on time elapsed
		fTime += DeltaTime;
		fTime = FMath::Clamp(fTime, 0, fLerpDuration);
		T = fTime / fLerpDuration;

		//smooth step
		float T1 = T * T;
		float T2 = 1.f - (1.f - T) * (1.f - T);
		float TFinal = FMath::Lerp(T1, T2, T);
		
		SetActorLocation(FMath::Lerp(PreviousPosition, TargetPosition, TFinal));
	}
	else
	{
		bMoving = false;
		fTime = 0;
	}
}

void APlayerActorClass::Fire()
{
	OnFireAction.Broadcast();
}

void APlayerActorClass::ChangePositionIndex(bool add)
{
	if (bMoving) { return; }
	
	if (add && iPositionIndex < 2)
	{
		iPositionIndex++;
	}
	else if (!add && iPositionIndex > 0)
	{
		iPositionIndex--;
	}
	
	PreviousPosition = TargetPosition;
	TargetPosition = LaneArray[iPositionIndex];
}

void APlayerActorClass::UpdateAABB()
{
	AABBMax = GetActorLocation() + FVector(fAABB_Depth/2, fAABB_Width/2, fAABB_Height);
	AABBMin = GetActorLocation() - FVector(fAABB_Depth/2, fAABB_Width/2, 0);
}



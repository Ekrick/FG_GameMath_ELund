

#include "Gameplay/ControllerClass.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Actors/PlayerActorClass.h"

void AControllerClass::BeginPlay()
{
	PlayerPawn = GetWorld()->SpawnActor<APlayerActorClass>(PlayerToSpawn, FVector::Zero(), FRotator::ZeroRotator);
	Possess(PlayerPawn);
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
	SetupPlayerInputComponent();
}

void AControllerClass::SetupPlayerInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveLeft, ETriggerEvent::Completed, this, &AControllerClass::MoveLeftInputAction);
		EnhancedInputComponent->BindAction(MoveRight, ETriggerEvent::Completed, this, &AControllerClass::MoveRightInputAction);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &AControllerClass::FireInputAction);

	}
}

void AControllerClass::MoveLeftInputAction()
{
	if (!PlayerPawn) { return; }

	PlayerPawn->ChangePositionIndex(true);
}

void AControllerClass::MoveRightInputAction()
{
	if (!PlayerPawn) { return; }

	PlayerPawn->ChangePositionIndex(false);
}

void AControllerClass::FireInputAction()
{
	if (!PlayerPawn) { return; }
	
	PlayerPawn->Fire();
}

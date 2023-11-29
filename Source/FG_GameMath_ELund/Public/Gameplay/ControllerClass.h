
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "ControllerClass.generated.h"

class UInputMappingContext;
class UInputAction;
class APlayerActorClass;

UCLASS()
class FG_GAMEMATH_ELUND_API AControllerClass : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "PlayerPawn", meta=(AllowPrivateAccess = "true"))
	TSubclassOf<APlayerActorClass> PlayerToSpawn;

protected:
	virtual void BeginPlay() override;

private:
	void SetupPlayerInputComponent();
	
	void MoveLeftInputAction();
	
	void MoveRightInputAction();

	void FireInputAction();

	TObjectPtr<APlayerActorClass> PlayerPawn;
};


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Noise_Experiment.generated.h"

UCLASS()
class FG_GAMEMATH_ELUND_API ANoise_Experiment : public AActor
{
	GENERATED_BODY()
	
public:	
	ANoise_Experiment();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Noise Mesh", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UProceduralMeshComponent> ProceduralMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Noise Mesh", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstance> Material;
	
	TArray<float> NoiseArray;
	TArray<FVector> NormalsArray;
	TArray<FVector> VerticesArray;
	TArray<FVector2D> UV_Array;

	//mesh properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Noise Mesh", meta=(AllowPrivateAccess = "true"))
	FVector MeshSize = FVector(500, 500, 100);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Noise Mesh", meta=(AllowPrivateAccess = "true"))
	int iMeshResolution = 128;

	//noise properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Noise Mesh", meta=(AllowPrivateAccess = "true"))
	float fNoiseScale = 0.05f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Noise Mesh", meta=(AllowPrivateAccess = "true"))
	float fNoiseStrength = 1.f;

	void SetupNoise();

	void CreateMesh();

};

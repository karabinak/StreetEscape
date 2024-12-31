// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadGenerator.generated.h"

class USplineComponent;
class USplineMeshComponent;

UCLASS()
class STREETESCAPE_API ARoadGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoadGenerator();

protected:
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

private:

	UPROPERTY(EditAnywhere)
	USplineComponent* Spline;

	UPROPERTY(EditAnywhere)
	TArray<USplineMeshComponent*> SplineMeshComponents;

	UPROPERTY(EditAnywhere)
	UStaticMesh* RoadMesh;


public:	
	virtual void Tick(float DeltaTime) override;

};

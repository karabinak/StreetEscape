// Fill out your copyright notice in the Description page of Project Settings.

#include "RoadGenerator.h"

#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"

ARoadGenerator::ARoadGenerator()
{
	PrimaryActorTick.bCanEverTick = true;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SetRootComponent(Spline);
}

void ARoadGenerator::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	int32 SplinePointsNum = Spline->GetNumberOfSplinePoints();
	int32 SplineSegmentsNum = Spline->GetNumberOfSplineSegments();

	if (SplineSegmentsNum > SplineMeshComponents.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn"));
		USplineMeshComponent* SplineMeshComp = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass());

		//SplineMeshComp->SetupAttachment(GetRootComponent());
		if (RoadMesh)
		{
			SplineMeshComp->SetStaticMesh(RoadMesh);
		}
		SplineMeshComp->RegisterComponent();
		SplineMeshComponents.Add(SplineMeshComp);
	}

	for (int32 i = 0; i < SplinePointsNum - 1; i++)
	{
		FVector StartPoint = Spline->GetSplinePointAt(i, ESplineCoordinateSpace::Local).Position;
		FVector StartTangentPoint = Spline->GetTangentAtSplinePoint(i, ESplineCoordinateSpace::Local);
		FVector EndPoint = Spline->GetSplinePointAt(i + 1, ESplineCoordinateSpace::Local).Position;
		FVector EndTangentPoint = Spline->GetTangentAtSplinePoint(i + 1, ESplineCoordinateSpace::Local);

		SplineMeshComponents[i]->SetWorldLocation(Spline->GetComponentLocation());
		SplineMeshComponents[i]->SetStartAndEnd(StartPoint, StartTangentPoint, EndPoint, EndTangentPoint);
		//SplineMeshComponents[i]->UpdateMesh();
	}
}

void ARoadGenerator::BeginPlay()
{
	Super::BeginPlay();


	
}


void ARoadGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


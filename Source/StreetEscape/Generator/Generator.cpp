// Fill out your copyright notice in the Description page of Project Settings.


#include "Generator.h"
#include "StreetEscape/Road/Road.h"

AGenerator::AGenerator()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AGenerator::BeginPlay()
{
	Super::BeginPlay();

	// Always spawn this pattern first
	PatternToSpawn = AvailableRoadPatterns[0].RoadPattern;
	
	CreateRoad();
	CreateRoad();
	CreateRoad();
	CreateRoad();
	CreateRoad();
	CreateRoad();
	CreateRoad();
	CreateRoad();
	CreateRoad();
	CreateRoad();
}

void AGenerator::CreateRoad()
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	TSubclassOf<ARoad> RoadClass;
	ARoad* Road;

	SelectRoad(RoadClass);
	SpawnRoad(RoadClass, SpawnParameters, Road);
	DestroyLastRoad();

	SetLocationAndRotation(Road);
	RandomActivePattern();
}

void AGenerator::SelectRoad(TSubclassOf<ARoad>& RoadClass)
{
	if (bIsPatternActive)
	{
		if (PatternToSpawn.IsEmpty())
		{
			int32 RandomInt = FMath::RandRange(0, AvailableRoadPatterns.Num() - 1);
			PatternToSpawn = AvailableRoadPatterns[RandomInt].RoadPattern;
		}

		RoadClass = PatternToSpawn[0];
		PatternToSpawn.RemoveAt(0);

		if (PatternToSpawn.IsEmpty())
		{
			bIsPatternActive = false;
		}
	}
	else
	{
		int32 RandomInt = FMath::RandRange(0, AvailableRoads.Num() - 1);
		RoadClass = AvailableRoads[RandomInt];
	}
}

void AGenerator::SpawnRoad(TSubclassOf<ARoad>& RoadClass, FActorSpawnParameters& SpawnParameters, ARoad*& Road)
{
	Road = GetWorld()->SpawnActor<ARoad>(RoadClass, SpawnPoint, SpawnRotation, SpawnParameters);
	SpawnedRoads.Add(Road);
}

void AGenerator::DestroyLastRoad()
{
	if (SpawnedRoads.Num() > MaxRoadSpawn)
	{
		SpawnedRoads[0]->Destroy();
		SpawnedRoads.RemoveAt(0);
	}
}

void AGenerator::SetLocationAndRotation(ARoad* Road)
{
	TArray<FName> Sockets = Road->GetRoadMesh()->GetAllSocketNames();
	int32 RandomSocket = FMath::RandRange(0, Sockets.Num() - 1);

	SpawnPoint = Road->GetRoadMesh()->GetSocketLocation(Sockets[RandomSocket]);
	SpawnRotation = Road->GetRoadMesh()->GetSocketRotation(Sockets[RandomSocket]);
}

void AGenerator::RandomActivePattern()
{
	if (!bIsPatternActive)
	{
		if (PatternChance >= FMath::FRandRange(0.0f, 1.0f))
		{
			bIsPatternActive = true;
		}
	}
}
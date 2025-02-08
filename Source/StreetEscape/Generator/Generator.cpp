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
	CreateRoad();
	CreateRoad();
}

void AGenerator::CreateRoad()
{
	SelectRoad();
	SpawnRoad();
	DestroyLastRoad();

	SetLocationAndRotation();
	RandomActivePattern();
}

void AGenerator::SelectRoad()
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

void AGenerator::SpawnRoad(bool NormalRoad)
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	if (NormalRoad)
	{
		Road = GetWorld()->SpawnActor<ARoad>(RoadClass, SpawnPoint, SpawnRotation, SpawnParameters);
		SpawnedRoads.Add(Road);
	}
	else
	{
		ARoad* TempEndRoad = GetWorld()->SpawnActor<ARoad>(ClassRoadEnd, SpawnPoint, SpawnRotation, SpawnParameters);
		SpawnedRoads.Add(TempEndRoad);
	}
}

void AGenerator::DestroyLastRoad()
{
	if (SpawnedRoads.Num() > MaxRoadSpawn)
	{
		SpawnedRoads[0]->Destroy();
		SpawnedRoads.RemoveAt(0);
	}
}

void AGenerator::SetLocationAndRotation()
{
	TArray<FName> Sockets = Road->GetRoadMesh()->GetAllSocketNames();

	int32 RandomSocket = 0;
	if (Sockets.Num() > 1)
	{
		if (LastRoadLeft)
		{
			RandomSocket = FMath::RandRange(1, Sockets.Num() - 1);
		}
		if (LastRoadRight)
		{
			RandomSocket = FMath::RandRange(0, Sockets.Num() - 2);
		}
		if (LastRoadRight == false && LastRoadLeft == false)
		{
			RandomSocket = FMath::RandRange(0, Sockets.Num() - 1);
		}

		if (RandomSocket == 0)
		{
			LastRoadRight = false;
			LastRoadLeft = true;
		}


		if (RandomSocket == 2)
		{
			LastRoadLeft = false;
			LastRoadRight = true;
		}
	}
	else
	{
		RandomSocket = FMath::RandRange(0, Sockets.Num() - 1);
	}


	if (Sockets.Num() > 1)
	{
		int32 RoadEndingsToSpawn = Sockets.Num() - 1;

		for (int32 i = 0; i <= RoadEndingsToSpawn; i++)
		{
			if (Sockets[i] == Sockets[RandomSocket]) continue;

			SpawnPoint = Road->GetRoadMesh()->GetSocketLocation(Sockets[i]);
			SpawnRotation = Road->GetRoadMesh()->GetSocketRotation(Sockets[i]);
			FActorSpawnParameters SpawnParameters;
			SpawnRoad(false);
		}
	}

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
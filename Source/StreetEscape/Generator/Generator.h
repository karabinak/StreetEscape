// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Generator.generated.h"

class ARoad;

USTRUCT(BlueprintType)
struct FRoadPattern
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RoadPatterns", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<ARoad>> RoadPattern;
};

UCLASS()
class STREETESCAPE_API AGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	AGenerator();

protected:
	virtual void BeginPlay() override;


	void SelectRoad(TSubclassOf<ARoad>& RoadClass);
	void SpawnRoad(TSubclassOf<ARoad>& RoadClass, FActorSpawnParameters& SpawnParameters, ARoad*& Road);
	void DestroyLastRoad();
	void SetLocationAndRotation(ARoad* Road);
	void RandomActivePattern();

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<ARoad>> AvailableRoads;

	UPROPERTY(VisibleAnywhere, Category = "Road", meta = (AllowPrivateAccess = "true"))
	TArray<ARoad*> SpawnedRoads;

	UPROPERTY(EditAnywhere, Category = "Road", meta = (AllowPrivateAccess = "true"))
	int32 MaxRoadSpawn = 10;

	UPROPERTY(VisibleAnywhere, Category = "Road", meta = (AllowPrivateAccess = "true"))
	FVector SpawnPoint = FVector(1005.5f, 0.f, 0.f);

	UPROPERTY(VisibleAnywhere, Category = "Road", meta = (AllowPrivateAccess = "true"))
	FRotator SpawnRotation = FRotator::ZeroRotator;

	// Patterns generator
	UPROPERTY()
	bool bIsPatternActive = true;

	UPROPERTY(EditAnywhere, Category = "Road Pattern", meta = (AllowPrivateAccess = "true"))
	float PatternChance = 0.3f;

	UPROPERTY(EditAnywhere, Category = "Road Pattern", meta = (AllowPrivateAccess = "true"))
	TArray<FRoadPattern> AvailableRoadPatterns;

	UPROPERTY(VisibleAnywhere, Category = "Road Pattern", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<ARoad>> PatternToSpawn;

public:	
	
	void CreateRoad();





};

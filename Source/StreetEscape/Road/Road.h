// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Road.generated.h"

class UBoxComponent;

UENUM(BlueprintType)
enum class ERoadType : uint8
{
	ERT_Straight UMETA(DisplayName = "Straight"),
	ERT_Custom UMETA(DisplayName = "Custom"),

	ERT_MAX UMETA(DisplayName = "Default")
};

UCLASS()
class STREETESCAPE_API ARoad : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoad();


protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSpawnTriggerBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* RoadMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	int32 BuildingsToGenerate = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	FVector StartPos = FVector(0.f, 1200.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	float Distance = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	ERoadType RoadType = ERoadType::ERT_Straight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generator", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMesh*> BuildingsMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* SpawnTrigger;

public:	
	
	FORCEINLINE UStaticMeshComponent* GetRoadMesh() const { return RoadMesh; }

};

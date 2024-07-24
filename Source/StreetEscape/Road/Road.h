// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Road.generated.h"

class UBoxComponent;

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
	UBoxComponent* SpawnTrigger;

public:	
	
	FORCEINLINE UStaticMeshComponent* GetRoadMesh() const { return RoadMesh; }

};

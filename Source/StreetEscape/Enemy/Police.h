// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "Police.generated.h"

class USphereComponent;
class AVehicle;

UCLASS()
class STREETESCAPE_API APolice : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:

	APolice();

	void Steer(float AxisValue);
	void Throttle(float AxisValue);
	void Brake(float AxisValue);

protected:

	UFUNCTION()
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverlappingWithPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void StopOverlappingWithPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void CheckPlayerDistance();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	AVehicle* PlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	USphereComponent* ArrestedZone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	float DestroyDistance = 8000.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	float SpawnForce = 3000000.f;

	UPROPERTY()
	FTimerHandle DistanceToPlayerTimer;


public:


	
};

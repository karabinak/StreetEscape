// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "StreetEscape/Data/VehicleData.h"
#include "Vehicle.generated.h"


class USpringArmComponent;
class UCameraComponent;

UCLASS()
class STREETESCAPE_API AVehicle : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:

	AVehicle();

	void Steer(float AxisValue);
	void Throttle(float AxisValue);
	void Brake(float AxisValue);

protected:

	UFUNCTION()
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Meshes", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WheelFR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Meshes", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WheelFL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Meshes", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WheelRR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Meshes", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WheelRL;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data", meta = (AllowPrivateAccess = "true"))
	FVehicleData VehicleData;

	UPROPERTY(VisibleAnywhere, Category = "Distance")
	float Distance = 0.f;

	UPROPERTY(VisibleAnywhere, Category = "Distance")
	FVector LastFrameLocation = FVector(0.f, 0.f, 0.f);

	UPROPERTY(VisibleAnywhere, Category = "Distance")
	bool CalculateDistance = false;

public:

	void SetCalculateDistance(bool InCalculateDistance) { CalculateDistance = InCalculateDistance; }
};

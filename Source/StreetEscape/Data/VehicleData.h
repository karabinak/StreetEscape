// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VehicleData.generated.h"

//class UVehicle;

USTRUCT(BlueprintType)
struct FWheelData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMesh* TempWheel;

	UPROPERTY(EditAnywhere)
	UMaterial* TempWheelColor;

	/* TO IMPLEMENT MORE ADVANCED WHEEL TUNING */
	//UPROPERTY(EditAnywhere)
	//UStaticMesh* RimMesh;

	//UPROPERTY(EditAnywhere)
	//UStaticMesh* TyreMesh;

	//UPROPERTY(EditAnywhere, meta = (ClampMin = "10", ClampMax = "20"))
	//int32 RimSize;

	//UPROPERTY(EditAnywhere)
	//UMaterial* RimColor;

};

USTRUCT(BlueprintType)
struct FColorsData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UMaterial* BodyFirstColor;

	UPROPERTY(EditAnywhere)
	UMaterial* BodySecondColor;

	UPROPERTY(EditAnywhere)
	UMaterial* WindshieldColor;
};

USTRUCT(BlueprintType)
struct FVehicleData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FColorsData Colors;

	UPROPERTY(EditAnywhere)
	FWheelData WheelFR;

	UPROPERTY(EditAnywhere)
	FWheelData WheelFL;

	UPROPERTY(EditAnywhere)
	FWheelData WheelRR;

	UPROPERTY(EditAnywhere)
	FWheelData WheelRL;


};
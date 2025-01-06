// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OfferData.generated.h"

class AVehicle;

UENUM(BlueprintType)
enum class EOfferType : uint8
{
	EOT_Vehicle UMETA(DisplayName = "Vehicle"),
	EOT_Wheel UMETA(DisplayName = "Wheel"),

	EOT_MAX UMETA(DisplayName = "Default")
};

USTRUCT(BlueprintType)
struct FVehicleOffer
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AVehicle> Vehicle;

	UPROPERTY(EditAnywhere)
	FText VehicleName;

	UPROPERTY(EditAnywhere)
	int32 VehiclePrice;

	UPROPERTY(VisibleAnywhere)
	bool VehicleOwned;

	UPROPERTY(VisibleAnywhere)
	EOfferType OfferType = EOfferType::EOT_Vehicle;
};

USTRUCT(BlueprintType)
struct FWheelOffer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMesh* WheelMesh;

	UPROPERTY(EditAnywhere)
	FText WheelName;

	UPROPERTY(VisibleAnywhere)
	EOfferType OfferType = EOfferType::EOT_Wheel;
};
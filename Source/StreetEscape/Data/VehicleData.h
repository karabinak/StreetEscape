// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VehicleData.generated.h"

//class UVehicle;

USTRUCT(BlueprintType)
struct FVehicleData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	UMaterial* BodyPaint;
};
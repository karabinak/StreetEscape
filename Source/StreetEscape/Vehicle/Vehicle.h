// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "VehicleStructs.h"
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

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	FText VehicleName = FText::FromName(TEXT("Vehicle1"));

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	FCustomization Customization;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	FUpgrade Upgrade;

public:
	FORCEINLINE FText GetVehicleName() const { return VehicleName; }

};

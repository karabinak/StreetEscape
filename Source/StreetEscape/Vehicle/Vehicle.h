// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
//#include "StreetEscape/Data/VehicleData.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	//FCustomization Customization;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	//FUpgrade Upgrade;

public:

};

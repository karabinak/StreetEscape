// Fill out your copyright notice in the Description page of Project Settings.

#include "Vehicle.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ChaosVehicleMovementComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"

AVehicle::AVehicle()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	SetRootComponent(GetMesh());
	SpringArm->SetupAttachment(GetRootComponent());
	Camera->SetupAttachment(SpringArm);


	UChaosWheeledVehicleMovementComponent* ChaosVehicleMovementComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());

	ChaosVehicleMovementComponent->EngineSetup.MaxRPM = 10000.f;
	ChaosVehicleMovementComponent->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
	ChaosVehicleMovementComponent->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 400.0f);
	ChaosVehicleMovementComponent->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(5000.0f, 500.0f);
	ChaosVehicleMovementComponent->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(10000.0f, 400.0f);

	ChaosVehicleMovementComponent->SteeringSetup.SteeringCurve.GetRichCurve()->Reset();
	ChaosVehicleMovementComponent->SteeringSetup.SteeringCurve.GetRichCurve()->AddKey(0.0f, 1.5f);
	ChaosVehicleMovementComponent->SteeringSetup.SteeringCurve.GetRichCurve()->AddKey(40.0f, 1.0f);
   
	ChaosVehicleMovementComponent->Mass = 1000.f;
	ChaosVehicleMovementComponent->DragCoefficient = 0.3f;
}

void AVehicle::Steer(float AxisValue)
{
	GetVehicleMovement()->SetSteeringInput(AxisValue);
}

void AVehicle::Throttle(float AxisValue)
{
	GetVehicleMovement()->SetThrottleInput(AxisValue);
}

void AVehicle::Brake(float AxisValue)
{
	GetVehicleMovement()->SetBrakeInput(AxisValue);
}

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
	WheelFR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelFR"));
	WheelFL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelFL"));
	WheelRR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelRR"));
	WheelRL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelRL"));

	SetRootComponent(GetMesh());
	SpringArm->SetupAttachment(GetRootComponent());
	Camera->SetupAttachment(SpringArm);
	WheelFR->SetupAttachment(GetMesh(), FName(TEXT("FR")));
	WheelFL->SetupAttachment(GetMesh(), FName(TEXT("FL")));
	WheelRR->SetupAttachment(GetMesh(), FName(TEXT("RR")));
	WheelRL->SetupAttachment(GetMesh(), FName(TEXT("RL")));


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

void AVehicle::BeginPlay()
{
	Super::BeginPlay();

	/* Load From VehicleDataStruct */
	if (VehicleData.WheelFR.TempWheel && VehicleData.WheelFL.TempWheel && VehicleData.WheelRR.TempWheel && VehicleData.WheelRL.TempWheel)
	{
		WheelFR->SetStaticMesh(VehicleData.WheelFR.TempWheel);
		WheelFL->SetStaticMesh(VehicleData.WheelFL.TempWheel);
		WheelRR->SetStaticMesh(VehicleData.WheelRR.TempWheel);
		WheelRL->SetStaticMesh(VehicleData.WheelRL.TempWheel);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TempWheels not valid"));
	}
}

void AVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CalculateDistance)
	{
		const FVector CurrentLocation = GetActorLocation();
		double DistanceOneSec = FVector::Dist(CurrentLocation, LastFrameLocation) * DeltaTime;

		Distance += DistanceOneSec / 100;
		LastFrameLocation = CurrentLocation;

		GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Emerald, FString::Printf(TEXT("%f m"), Distance));
	}
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
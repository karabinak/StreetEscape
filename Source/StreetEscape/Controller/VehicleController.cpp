// Fill out your copyright notice in the Description page of Project Settings.

#include "VehicleController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "StreetEscape/Vehicle/Vehicle.h"

AVehicleController::AVehicleController()
{

}

void AVehicleController::BeginPlay()
{
	SetShowMouseCursor(true);
}

void AVehicleController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(SetThrottleInput, ETriggerEvent::Triggered, this, &AVehicleController::OnThrottleTriggered);
		EnhancedInputComponent->BindAction(SetThrottleInput, ETriggerEvent::Completed, this, &AVehicleController::OnThrottleReleased);

		EnhancedInputComponent->BindAction(SetSteerInput, ETriggerEvent::Triggered, this, &AVehicleController::OnSteerTriggered);
		EnhancedInputComponent->BindAction(SetSteerInput, ETriggerEvent::Completed, this, &AVehicleController::OnSteerReleased);

		EnhancedInputComponent->BindAction(SetBrakeInput, ETriggerEvent::Triggered, this, &AVehicleController::OnBrakeTriggered);
		EnhancedInputComponent->BindAction(SetBrakeInput, ETriggerEvent::Completed, this, &AVehicleController::OnBrakeReleased);
	}
}

void AVehicleController::OnThrottleTriggered(const FInputActionValue& Value)
{
	AVehicle* Vehicle = Cast<AVehicle>(GetPawn());
	if (!Vehicle) return;

	const float ThrottleValue = Value.Get<float>();
	Vehicle->Throttle(ThrottleValue);
}

void AVehicleController::OnSteerTriggered(const FInputActionValue& Value)
{
	AVehicle* Vehicle = Cast<AVehicle>(GetPawn());
	if (!Vehicle) return;

	const float SteerValue = Value.Get<float>();
	Vehicle->Steer(SteerValue);
}

void AVehicleController::OnBrakeTriggered(const FInputActionValue& Value)
{
	AVehicle* Vehicle = Cast<AVehicle>(GetPawn());
	if (!Vehicle) return;

	const float BrakeValue = Value.Get<float>();
	Vehicle->Brake(BrakeValue);
}

void AVehicleController::OnThrottleReleased()
{
	AVehicle* Vehicle = Cast<AVehicle>(GetPawn());
	if (!Vehicle) return;

	Vehicle->Throttle(0.f);
}

void AVehicleController::OnSteerReleased()
{
	AVehicle* Vehicle = Cast<AVehicle>(GetPawn());
	if (!Vehicle) return;

	Vehicle->Steer(0.f);
}

void AVehicleController::OnBrakeReleased()
{
	AVehicle* Vehicle = Cast<AVehicle>(GetPawn());
	if (!Vehicle) return;

	Vehicle->Brake(0.f);
}

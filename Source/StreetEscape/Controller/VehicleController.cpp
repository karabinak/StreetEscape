// Fill out your copyright notice in the Description page of Project Settings.

#include "VehicleController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "StreetEscape/Vehicle/Vehicle.h"
#include "StreetEscape/Components/Inventory.h"

AVehicleController::AVehicleController()
{
	InventoryComponent = CreateDefaultSubobject<UInventory>(TEXT("InventoryComponent"));
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
	if (Vehicle)
	{
		const float ThrottleValue = Value.Get<float>();
		Vehicle->Throttle(ThrottleValue);
	}
	else
	{
		Vehicle = Cast<AVehicle>(GetPawn());
	}
}

void AVehicleController::OnSteerTriggered(const FInputActionValue& Value)
{
	if (Vehicle)
	{
		const float SteerValue = Value.Get<float>();
		Vehicle->Steer(SteerValue);
	}
	else
	{
		Vehicle = Cast<AVehicle>(GetPawn());
	}
}

void AVehicleController::OnBrakeTriggered(const FInputActionValue& Value)
{
	if (Vehicle)
	{
		const float BrakeValue = Value.Get<float>();
		Vehicle->Brake(BrakeValue);
	}
	else
	{
		Vehicle = Cast<AVehicle>(GetPawn());
	}
}

void AVehicleController::OnThrottleReleased()
{
	if (Vehicle)
	{
		Vehicle->Throttle(0.f);
	}
	else
	{
		Vehicle = Cast<AVehicle>(GetPawn());
	}
}

void AVehicleController::OnSteerReleased()
{
	if (Vehicle)
	{
		Vehicle->Steer(0.f);
	}
	else
	{
		Vehicle = Cast<AVehicle>(GetPawn());
	}
}

void AVehicleController::OnBrakeReleased()
{
	if (Vehicle)
	{
		Vehicle->Brake(0.f);
	}
	else
	{
		Vehicle = Cast<AVehicle>(GetPawn());
	}
}

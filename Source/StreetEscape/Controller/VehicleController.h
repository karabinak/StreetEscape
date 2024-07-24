// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "VehicleController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class STREETESCAPE_API AVehicleController : public APlayerController
{
	GENERATED_BODY()

public:

	AVehicleController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SetThrottleInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SetSteerInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SetBrakeInput;

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void OnThrottleTriggered(const FInputActionValue& Value);
	void OnSteerTriggered(const FInputActionValue& Value);
	void OnBrakeTriggered(const FInputActionValue& Value);
	void OnThrottleReleased();
	void OnSteerReleased();
	void OnBrakeReleased();

private:


public:




	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hideout.generated.h"

class USpringArmComponent;
class UCameraComponent;

class AVehicleController;
class UShop;
class UCustomization;

UCLASS()
class STREETESCAPE_API AHideout : public AActor
{
	GENERATED_BODY()
	
public:	
	AHideout();

	//virtual void Tick(float DeltaTime) override;

	//void SetLevel();

	//void InitializeWidgets();

protected:
	virtual void BeginPlay() override;

	

private:

	UPROPERTY(EditAnywhere)
	UShop* Shop;
	UPROPERTY(EditAnywhere)
	UCustomization* Customization;

	UPROPERTY()
	AVehicleController* PC;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Hideout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* VehicleStand;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;


public:	

	FORCEINLINE UStaticMeshComponent* GetVehicleStand() { return VehicleStand; }

	
	

};

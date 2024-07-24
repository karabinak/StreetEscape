// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hideout.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AVehicle;
class AHUDManager;
class AVehicleController;
class UMenuWidget;
class UShopVehicle;
class UCustomizationVehicle;

UCLASS()
class STREETESCAPE_API AHideout : public AActor
{
	GENERATED_BODY()
	
public:	
	AHideout();

	virtual void Tick(float DeltaTime) override;

	void SetLevel();

	void InitializeWidgets();

protected:
	virtual void BeginPlay() override;

	

private:

	UPROPERTY(EditAnywhere)
	UShopVehicle* ShopVehicle;
	UPROPERTY(EditAnywhere)
	UCustomizationVehicle* CustomizationVehicle;

	UPROPERTY()

	AHUDManager* HUD;
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> MenuWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	UMenuWidget* MenuWidget;


public:	

	
	

};

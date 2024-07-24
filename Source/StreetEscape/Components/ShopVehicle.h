// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShopVehicle.generated.h"

class AHideout;
class AVehicle;
class UVehicleOfferWidget;
class AHUDManager;

USTRUCT(BlueprintType)
struct FCatalogSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<AVehicle> Vehicle;

	UPROPERTY(VisibleAnywhere)
	UVehicleOfferWidget* CatalogWidget;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STREETESCAPE_API UShopVehicle : public UActorComponent
{
	GENERATED_BODY()

public:	
	UShopVehicle();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Initialize(AHUDManager* HUD);
	friend AHideout;

protected:
	//virtual void BeginPlay() override;

private:
	UPROPERTY()
	AHideout* Hideout;

	UPROPERTY(VisibleAnywhere)
	TArray<FCatalogSlot> VehicleCatalog;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AVehicle>> AvailableVehicles;

public:

	void SetHideout(AHideout* InHideout) { Hideout = InHideout; }
		
};

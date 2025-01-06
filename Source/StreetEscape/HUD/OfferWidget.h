// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StreetEscape/Data/OfferData.h"
#include "OfferWidget.generated.h"

class UButton;
class UTextBlock;
class AHideout;
class AVehicle;

DECLARE_DELEGATE_OneParam(FOnVehicleOfferClickedSignature, FVehicleOffer /*VehicleOffer*/);
DECLARE_DELEGATE_OneParam(FOnWheelOfferClickedSignature, FWheelOffer /*WheelOffer*/);


UCLASS()
class STREETESCAPE_API UOfferWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	FOnVehicleOfferClickedSignature OnVehicleOfferClickedDelegate;
	FOnWheelOfferClickedSignature OnWheelOfferClickedDelegate;

	void SetupWidget(FVehicleOffer InVehicleOfferData);

	void UpdateProperties();

protected:

	virtual void NativeConstruct();

	UFUNCTION()
	void OnSelectButtonClicked();


private:
	UPROPERTY(meta = (BindWidget))
	UButton* SelectButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* VehiclePriceText;

	//UPROPERTY(VisibleAnywhere)
	//EOfferType OfferType;

	//UPROPERTY(VisibleAnywhere)
	//TSubclassOf<AVehicle> Vehicle;

	//UPROPERTY(VisibleAnywhere)
	//bool OfferOwned = false;

	UPROPERTY(VisibleAnywhere)
	FVehicleOffer VehicleOfferData;

	UPROPERTY(VisibleAnywhere)
	FWheelOffer WheelOfferData;

	//UPROPERTY(VisibleAnywhere)
	//UObject* Owner;
	
public:

	//FORCEINLINE void SetOfferType(EOfferType InOfferType) { OfferType = InOfferType; }
	//FORCEINLINE void SetVehicle(TSubclassOf<AVehicle> InVehicle) { Vehicle = InVehicle; }
	//FORCEINLINE void SetOfferOwned(bool InOfferOwned) { OfferOwned = InOfferOwned; }
	FORCEINLINE void SetOfferOwned(bool OfferOwned) { VehicleOfferData.VehicleOwned = OfferOwned; }
	
};

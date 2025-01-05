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

DECLARE_DELEGATE_OneParam(FOnVehicleOfferClickedSignature, TSubclassOf<AVehicle> /*Vehicle*/);
DECLARE_DELEGATE_OneParam(FOnWheelOfferClickedSignature, FWheelOffer /*WheelOffer*/);


UCLASS()
class STREETESCAPE_API UOfferWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	FOnVehicleOfferClickedSignature OnVehicleOfferClickedDelegate;
	FOnWheelOfferClickedSignature OnWheelOfferClickedDelegate;


protected:

	virtual void NativeConstruct();


	UFUNCTION()
	void OnSelectButtonClicked();


private:
	UPROPERTY(meta = (BindWidget))
	UButton* SelectButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* VehicleNameText;

	UPROPERTY()
	AHideout* Hideout;
	
	UPROPERTY(VisibleAnywhere)
	EOfferType OfferType;

	UPROPERTY(VisibleAnywhere)
	TSubclassOf<AVehicle> Vehicle;

	UPROPERTY(VisibleAnywhere)
	FWheelOffer WheelOfferData;
	
public:

	FORCEINLINE void SetOfferType(EOfferType InOfferType) { OfferType = InOfferType; }
	FORCEINLINE void SetVehicle(TSubclassOf<AVehicle> InVehicle) { Vehicle = InVehicle; }
	void SetProperties(FText InVehicleName);
	//FORCEINLINE void SetHideout(AHideout* InHieout) { Hideout = InHieout; }
	//FORCEINLINE void SetVehicle(TSubclassOf<AVehicle> InVehicle) { Vehicle = InVehicle; }
};

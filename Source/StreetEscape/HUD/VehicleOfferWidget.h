// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VehicleOfferWidget.generated.h"

class UButton;
class UTextBlock;
class AHideout;
class AVehicle;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVehicleOfferClickedSignature, TSubclassOf<AVehicle>, Vehicle);

USTRUCT(BlueprintType)
struct FCatalogInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName VehicleName = FName(TEXT("DefaultVehicle"));
};

UCLASS()
class STREETESCAPE_API UVehicleOfferWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnVehicleOfferClickedSignature OnVehicleOfferClickedDelegate;


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

	UPROPERTY()
	TSubclassOf<AVehicle> Vehicle;
	
public:

	void SetProperties(FText InVehicleName);
	FORCEINLINE void SetHideout(AHideout* InHieout) { Hideout = InHieout; }
	FORCEINLINE void SetVehicle(TSubclassOf<AVehicle> InVehicle) { Vehicle = InVehicle; }
};

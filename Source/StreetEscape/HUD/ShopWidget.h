// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"

class UCanvasPanel;
class UScrollBox;
class UButton;
class UTextBlock;

class AVehicle;
class UShop;
class UOfferWidget;

UCLASS()
class STREETESCAPE_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void AddOfferWidget(UOfferWidget* OfferToAdd);

	void UpdatePriceText(FText Price);

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnPlayButtonClicked();
	UFUNCTION()
	void OnCustomizationButtonClicled();
	UFUNCTION()
	void OnBuyButtonClicked();

	//UFUNCTION()
	//void OnVehicleOfferClicked(TSubclassOf<AVehicle> Vehicle);

private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Canvas;

	UPROPERTY(meta = (BindWidget))
	UButton* PlayButton;

	UPROPERTY(meta = (BindWidget))
	UButton* BuyButton;

	UPROPERTY(meta = (BindWidget))
	UButton* CustomizationButton;

	UPROPERTY(meta = (BindWidget))
	UScrollBox* ScrollBox;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* VehiclePriceText;

	UPROPERTY(VisibleAnywhere)
	UShop* OwnerClass;

public:

	FORCEINLINE void SetOwner(UShop* Owner) { OwnerClass = Owner; }
	
};

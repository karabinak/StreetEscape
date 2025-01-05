// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"

class UCanvasPanel;
class UScrollBox;

class AVehicle;
class UShop;
class UOfferWidget;

UCLASS()
class STREETESCAPE_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void AddOfferWidget(UOfferWidget* OfferToAdd);

protected:
	virtual void NativeConstruct() override;

	//UFUNCTION()
	//void OnVehicleOfferClicked(TSubclassOf<AVehicle> Vehicle);

private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Canvas;

	UPROPERTY(meta = (BindWidget))
	UScrollBox* ScrollBox;

	//UPROPERTY(VisibleAnywhere)
	//UShop* Owner;


public:

	
	//FORCEINLINE void InitializeWidget(UShop* InOwner) { Owner = InOwner; }
};

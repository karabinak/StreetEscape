// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"
#include "Components/ScrollBox.h"
#include "Components/CanvasPanel.h"
#include "Components/ScrollBoxSlot.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "OfferWidget.h"
#include "StreetEscape/Vehicle/Vehicle.h"
#include "StreetEscape/Components/Shop.h"
//#include "StreetEscape/Controller/VehicleController.h"
//#include "StreetEscape/Components/Inventory.h"
//#include "Kismet/GameplayStatics.h"


void UShopWidget::NativeConstruct()
{
	PlayButton->OnClicked.AddDynamic(this, &UShopWidget::OnPlayButtonClicked);
	CustomizationButton->OnClicked.AddDynamic(this, &UShopWidget::OnCustomizationButtonClicked);
	BuyButton->OnClicked.AddDynamic(this, &UShopWidget::OnBuyButtonClicked);

	PlayButton->SetVisibility(ESlateVisibility::Collapsed);
	CustomizationButton->SetVisibility(ESlateVisibility::Collapsed);
}

void UShopWidget::OnPlayButtonClicked()
{
	OwnerClass->StartLevel();
}

void UShopWidget::OnCustomizationButtonClicked()
{

}

void UShopWidget::OnBuyButtonClicked()
{
	OwnerClass->OnBuyButtonPressed();
}

void UShopWidget::UpdatePriceText(FText Price)
{
	VehiclePriceText->SetText(Price);
}

void UShopWidget::OnVehicleOwnedChanged(bool IsPlayerOwningVehicle)
{
	if (IsPlayerOwningVehicle)
	{
		BuyButton->SetVisibility(ESlateVisibility::Collapsed);
		PlayButton->SetVisibility(ESlateVisibility::Visible);
		CustomizationButton->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		BuyButton->SetVisibility(ESlateVisibility::Visible);
		PlayButton->SetVisibility(ESlateVisibility::Collapsed);
		CustomizationButton->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UShopWidget::AddOfferWidget(UOfferWidget* OfferToAdd)
{
	ScrollBox->AddChild(OfferToAdd);
}

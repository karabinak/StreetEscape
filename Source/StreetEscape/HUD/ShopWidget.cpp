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
	CustomizationButton->OnClicked.AddDynamic(this, &UShopWidget::OnCustomizationButtonClicled);
	BuyButton->OnClicked.AddDynamic(this, &UShopWidget::OnBuyButtonClicked);
}

void UShopWidget::OnPlayButtonClicked()
{

}

void UShopWidget::OnCustomizationButtonClicled()
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

void UShopWidget::AddOfferWidget(UOfferWidget* OfferToAdd)
{
	ScrollBox->AddChild(OfferToAdd);
}

//void UShopWidget::OnVehicleOfferClicked(TSubclassOf<AVehicle> Vehicle)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Delegate Works"));
	// Owner->SpawnVehicle(Vehicle);
	// Works
	// Cast<AVehicleController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->GetInventoryComponent()->AddToInventory(Vehicle);
//}

//UVehicleOfferWidget* UShopWidget::CreateCatalogWidgets(TSubclassOf<AVehicle> InVehicle)
//{
	//UVehicleOfferWidget* OfferWidget = CreateWidget<UVehicleOfferWidget>(this, VehicleCatalogClass);
	//OfferWidget->OnVehicleOfferClickedDelegate.AddUniqueDynamic(this, &UShopWidget::OnVehicleOfferClicked);

	//VehicleCatalogWidgets.Add(OfferWidget);
	//ScrollBox->AddChild(OfferWidget);
	//OfferWidget->SetVehicle(InVehicle);
	//OfferWidget->SetProperties(InVehicle.GetDefaultObject()->GetVehicleName());
	//OfferWidget->SetPadding(FMargin::FMargin(FVector2d(37.33f, 37.33f)));


	//return OfferWidget;
//}

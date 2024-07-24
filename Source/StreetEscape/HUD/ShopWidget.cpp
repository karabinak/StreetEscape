// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"
#include "VehicleOfferWidget.h"
#include "StreetEscape/Vehicle/Vehicle.h"
#include "Components/ScrollBox.h"
#include "Components/CanvasPanel.h"
#include "Components/ScrollBoxSlot.h"

void UShopWidget::NativeConstruct()
{
	UE_LOG(LogTemp, Warning, TEXT("Shop"));
}

UVehicleOfferWidget* UShopWidget::CreateCatalogWidget(TSubclassOf<AVehicle> InVehicle, AHideout* InHideout)
{
	UVehicleOfferWidget* OfferWidget = CreateWidget<UVehicleOfferWidget>(this, VehicleCatalogClass);
	VehicleCatalogWidgets.Add(OfferWidget);
	ScrollBox->AddChild(OfferWidget);
	OfferWidget->SetHideout(InHideout);
	OfferWidget->SetVehicle(InVehicle);
	OfferWidget->SetProperties(InVehicle.GetDefaultObject()->GetVehicleName());
	OfferWidget->SetPadding(FMargin::FMargin(FVector2d(37.33f, 37.33f)));

	return OfferWidget;
}

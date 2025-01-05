// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"
#include "OfferWidget.h"
#include "StreetEscape/Vehicle/Vehicle.h"
#include "Components/ScrollBox.h"
#include "Components/CanvasPanel.h"
#include "Components/ScrollBoxSlot.h"
//#include "StreetEscape/Controller/VehicleController.h"
//#include "StreetEscape/Components/Inventory.h"
//#include "Kismet/GameplayStatics.h"
//#include "StreetEscape/Components/ShopVehicle.h"


void UShopWidget::NativeConstruct()
{
	
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

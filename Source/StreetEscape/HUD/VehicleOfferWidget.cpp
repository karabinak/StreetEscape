// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleOfferWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "StreetEscape/Hideout/Hideout.h"
#include "StreetEscape/Vehicle/Vehicle.h"

void UVehicleOfferWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SelectButton->OnClicked.AddDynamic(this, &UVehicleOfferWidget::OnSelectButtonClicked);
}

void UVehicleOfferWidget::OnSelectButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked"));

	if (Vehicle && Hideout)
	{
		Hideout->SpawnVehicle(Vehicle);
	}
}

void UVehicleOfferWidget::SetProperties(FText InVehicleName)
{
	VehicleNameText->SetText(InVehicleName);
}

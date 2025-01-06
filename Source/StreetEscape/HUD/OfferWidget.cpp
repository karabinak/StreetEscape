 // Fill out your copyright notice in the Description page of Project Settings.


#include "OfferWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

//#include "StreetEscape/Hideout/Hideout.h"
#include "StreetEscape/Vehicle/Vehicle.h"

void UOfferWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SelectButton->OnClicked.AddDynamic(this, &UOfferWidget::OnSelectButtonClicked);
}

void UOfferWidget::OnSelectButtonClicked()
{
	switch (OfferType)
	{
	case EOfferType::EOT_Vehicle:

		OnVehicleOfferClickedDelegate.Execute(VehicleOfferData);
		break;

	case EOfferType::EOT_Wheel:

		OnWheelOfferClickedDelegate.Execute(WheelOfferData);
		UE_LOG(LogTemp, Warning, TEXT("WheelOfferDelegateWorks"));
		break;

	case EOfferType::EOT_MAX:

		break;

	default:

		break;
	}

}

void UOfferWidget::SetProperties(FText InVehicleName)
{
	if (OfferOwned)
	{
		VehiclePriceText->SetText(FText::FromString("OWNED"));
	}
	else
	{
		VehiclePriceText->SetText(InVehicleName);
	}
}
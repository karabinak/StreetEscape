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
	VehiclePriceText->SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UOfferWidget::SetupWidget(FVehicleOffer InVehicleOfferData)
{
	VehicleOfferData = InVehicleOfferData;
	VehicleOfferData.OfferWidget = this;
	SetPadding(FMargin::FMargin(FVector2d(37.33f, 37.33f)));
	UpdateProperties();
}

void UOfferWidget::OnSelectButtonClicked()
{
	switch (VehicleOfferData.OfferType)
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

void UOfferWidget::UpdateProperties()
{
	if (VehicleOfferData.VehicleOwned)
	{
		VehiclePriceText->SetText(FText::FromString("OWNED"));
		UE_LOG(LogTemp, Warning, TEXT("Owned"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NotOwned"));
		VehiclePriceText->SetText(FText::FromString(FString::FromInt(VehicleOfferData.VehiclePrice)));
	}
}
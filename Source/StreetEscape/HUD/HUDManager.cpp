// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDManager.h"
#include "Blueprint/UserWidget.h"

#include "ShopWidget.h"
#include "OfferWidget.h"

void AHUDManager::BeginPlay()
{
	
}

void AHUDManager::ChangeWidgetState(EWidgetState InWidgetState)
{
	switch (InWidgetState)
	{
	case EWidgetState::EWS_Shop:
		if (ShopWidget == nullptr) return;

		if (!ShopWidget->IsInViewport())
		{
			ShopWidget->AddToViewport();
		}
		ShopWidget->SetVisibility(ESlateVisibility::Visible);


		break;
	case EWidgetState::EWS_Customization:



		break;

	case EWidgetState::EWS_Gameplay:



		break;
	}
}
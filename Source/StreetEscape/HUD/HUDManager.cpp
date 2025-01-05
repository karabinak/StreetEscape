// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDManager.h"
#include "Blueprint/UserWidget.h"

#include "MenuWidget.h"
#include "ShopWidget.h"
#include "OfferWidget.h"

void AHUDManager::BeginPlay()
{
	//SetupWidgets(WidgetState);
}

//void AHUDManager::SetupWidgets(EWidgetState InWidgetState)
//{
//	switch (InWidgetState)
//	{
//	case EWidgetState::EWS_Hideout:
//
//
//
//		break;
//	case EWidgetState::EWS_Gameplay:
//
//		ActiveGameplayWidgets();
//
//		break;
//	}
//}
//
//void AHUDManager::CreateMenuWidget(AHideout* InHideout)
//{
//	if (MenuWidgetClass)
//	{
//		MenuWidget = CreateWidget<UMenuWidget>(GetWorld(), MenuWidgetClass);
//		MenuWidget->SetHideout(InHideout);
//		MenuWidget->AddToViewport();
//	}
//}
//
//void AHUDManager::CreateShopWidget()
//{
//	if (ShopWidgetClass)
//	{
//		ShopWidget = CreateWidget<UShopWidget>(GetWorld(), ShopWidgetClass);
//		ShopWidget->AddToViewport();
//	}
//}
//
//void AHUDManager::ActiveGameplayWidgets()
//{
//	MenuWidget->RemoveFromParent();
//	ShopWidget->RemoveFromParent();
//}
//
//void AHUDManager::ActiveHideoutWidgets()
//{
//	CreateMenuWidget(Hideout);
//	CreateShopWidget();
//}
//
//void AHUDManager::DeactiveGameplayWidgets()
//{
//
//}
//
//void AHUDManager::DeactiveHideoutWidgets()
//{
//
//}
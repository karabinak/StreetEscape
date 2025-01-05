// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop.h"

#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"


#include "StreetEscape/HUD/HUDManager.h"
#include "StreetEscape/HUD/ShopWidget.h"
#include "StreetEscape/HUD/OfferWidget.h"
#include "StreetEscape/Controller/VehicleController.h"
//#include "StreetEscape/Vehicle/Vehicle.h"
//#include "Inventory.h"


UShop::UShop()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UShop::BeginPlay()
{
	Super::BeginPlay();

    AVehicleController* PlayerController = Cast<AVehicleController>(UGameplayStatics::GetPlayerController(this, 0));
    AHUDManager* HUDManager = Cast<AHUDManager>(PlayerController->GetHUD());

    UShopWidget* ShopWidget = nullptr;
    if (ShopWidgetClass && HUDManager)
    {
        ShopWidget = CreateWidget<UShopWidget>(GetWorld(), ShopWidgetClass);
        HUDManager->SetShopWidget(ShopWidget);
        HUDManager->ChangeWidgetState(EWidgetState::EWS_Shop);
        //ShopWidget->SetOwner(this);
    }
    else
    {
        LOG_MISSINGCLASS("ShopComponent: No ShopWidgetClass selected or HUDManager not valid");
    }

    for (FVehicleOffer& ShopOffer : VehicleCatalog)
    {
        APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
        UOfferWidget* OfferWidget = CreateWidget<UOfferWidget>(GetWorld(), OfferWidgetClass);
        OfferWidget->OnVehicleOfferClickedDelegate.BindUObject(this, &UShop::VehicleOfferClicked);
        OfferWidget->SetPadding(FMargin::FMargin(FVector2d(37.33f, 37.33f)));
        OfferWidget->SetOfferType(EOfferType::EOT_Vehicle);
        OfferWidget->SetVehicle(ShopOffer.Vehicle);
        OfferWidget->SetProperties(ShopOffer.VehicleName);

        if (ShopWidget)
        {
            ShopWidget->AddOfferWidget(OfferWidget);
        }
    }
}

void UShop::VehicleOfferClicked(TSubclassOf<AVehicle> Vehicle)
{
    LOG_MISSINGCLASS("VehOffer Clicked");
}

//void UShop::SpawnVehicle(TSubclassOf<AVehicle> VehicleToSpawn)
//{
//    if (CurrentVehicle)
//    {
//        CurrentVehicle->Destroy();
//    }
//    if (MeshToAttach)
//    {
//        FActorSpawnParameters SpawnParameters;
//        CurrentVehicle = GetWorld()->SpawnActor<AVehicle>(VehicleToSpawn, MeshToAttach->GetComponentLocation(), MeshToAttach->GetComponentRotation(), SpawnParameters);
//        CurrentVehicle->GetMesh()->SetSimulatePhysics(false);
//        CurrentVehicle->AttachToComponent(MeshToAttach, FAttachmentTransformRules::KeepRelativeTransform);
//    }
//    else
//    {
//        UE_LOG(LogTemp, Warning, TEXT("NoMesh"));
//    }
//}
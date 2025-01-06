// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop.h"

#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

#include "StreetEscape/HUD/HUDManager.h"
#include "StreetEscape/HUD/ShopWidget.h"
#include "StreetEscape/HUD/OfferWidget.h"
#include "StreetEscape/Controller/VehicleController.h"
#include "StreetEscape/Vehicle/Vehicle.h"
#include "StreetEscape/Hideout/Hideout.h"
#include "Inventory.h"


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
        ShopWidget->SetOwner(this);
    }
    else
    {
        LOG_MISSINGCLASS("ShopComponent: No ShopWidgetClass selected or HUDManager not valid");
    }

    for (FVehicleOffer& ShopOffer : VehicleCatalog)
    {
        APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
        UOfferWidget* OfferWidget = CreateWidget<UOfferWidget>(GetWorld(), OfferWidgetClass);
        OfferWidget->OnVehicleOfferClickedDelegate.BindUObject(this, &UShop::OnVehicleOfferClicked);
        OfferWidget->SetPadding(FMargin::FMargin(FVector2d(37.33f, 37.33f)));
        OfferWidget->SetOfferType(EOfferType::EOT_Vehicle);
        OfferWidget->SetVehicle(ShopOffer.Vehicle);
        OfferWidget->SetOfferOwned(PlayerController->GetInventoryComponent()->IsInInventory(CurrentVehicleClass));
        OfferWidget->SetVehicleOffer(ShopOffer);
        OfferWidget->SetProperties(FText::FromString(FString::FromInt(ShopOffer.VehiclePrice)));

        if (ShopWidget)
        {
            ShopWidget->AddOfferWidget(OfferWidget);
        }
    }
}

void UShop::OnVehicleOfferClicked(FVehicleOffer VehicleOfferData)
{
    if (VehicleOfferData.Vehicle == CurrentVehicleClass) return;
    if (CurrentVehicle)
    {
        CurrentVehicle->Destroy();
    }
    UStaticMeshComponent* VehicleStand = Cast<AHideout>(GetOwner())->GetVehicleStand();
    if (VehicleStand && VehicleOfferData.Vehicle != nullptr)
    {
        FActorSpawnParameters SpawnParameters;
        CurrentVehicle = GetWorld()->SpawnActor<AVehicle>(VehicleOfferData.Vehicle, VehicleStand->GetSocketLocation(FName("socket")) + 100.f, VehicleStand->GetComponentRotation(), SpawnParameters);
        //CurrentVehicle->GetMesh()->SetSimulatePhysics(false);
        CurrentVehicle->AttachToComponent(VehicleStand, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
        CurrentVehicle->AddActorLocalOffset(FVector(0.f, 0.f, 20.f));

        CurrentVehicleClass = VehicleOfferData.Vehicle;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("NoMesh"));
    }

    AVehicleController* PlayerController = Cast<AVehicleController>(UGameplayStatics::GetPlayerController(this, 0));
    AHUDManager* HUDManager = Cast<AHUDManager>(PlayerController->GetHUD());

    if (PlayerController->GetInventoryComponent()->IsInInventory(CurrentVehicleClass))
    {
        HUDManager->GetShopWidget()->UpdatePriceText(FText::FromString("OWNED"));
        UE_LOG(LogTemp, Warning, TEXT("OWNED"));
    }
    else
    {
        HUDManager->GetShopWidget()->UpdatePriceText(FText::FromString(FString::FromInt(VehicleOfferData.VehiclePrice)));
        UE_LOG(LogTemp, Warning, TEXT("NOTOWNED"));
    }

    CurrentVehiclePrice = VehicleOfferData.VehiclePrice;
}

void UShop::OnBuyButtonPressed()
{
    AVehicleController* PlayerController = Cast<AVehicleController>(UGameplayStatics::GetPlayerController(this, 0));
    AHUDManager* HUDManager = Cast<AHUDManager>(PlayerController->GetHUD());
    UInventory* Inventory = PlayerController->GetInventoryComponent();
    if (PlayerController->GetPlayerCurrency() >= CurrentVehiclePrice)
    {
        if (!Inventory->IsInInventory(CurrentVehicleClass))
        {
            Inventory->AddToInventory(CurrentVehicleClass);
            PlayerController->SubtractPlayerCurrency(CurrentVehiclePrice);
            HUDManager->GetShopWidget()->UpdatePriceText(FText::FromString("OWNED"));
        }
    }
}

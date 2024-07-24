// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopVehicle.h"
#include "StreetEscape/HUD/HUDManager.h"
#include "StreetEscape/HUD/ShopWidget.h"
#include "StreetEscape/Hideout/Hideout.h"

UShopVehicle::UShopVehicle()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UShopVehicle::Initialize(AHUDManager* HUD)
{
    UE_LOG(LogTemp, Warning, TEXT("Shop"));

    HUD->CreateShopWidget();

    if (!AvailableVehicles.IsEmpty())
    {
        for (TSubclassOf<AVehicle>& Vehicle : AvailableVehicles)
        {
            UE_LOG(LogTemp, Warning, TEXT("Veh"));
            FCatalogSlot CatalogSlot;
            CatalogSlot.Vehicle = Vehicle;
            CatalogSlot.CatalogWidget = HUD->GetShopWidget()->CreateCatalogWidget(Vehicle, Hideout);
            VehicleCatalog.Add(CatalogSlot);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Empty"));
    }

   
}

//void UShopVehicle::BeginPlay()
//{
//	Super::BeginPlay();
//
//	
//}
//
//
//void UShopVehicle::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//
//}
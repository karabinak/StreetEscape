// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopVehicle.h"
#include "StreetEscape/Vehicle/Vehicle.h"
#include "Kismet/GameplayStatics.h"
//#include "StreetEscape/HUD/HUDManager.h"
#include "Blueprint/UserWidget.h"
#include "StreetEscape/HUD/ShopWidget.h"
#include "Inventory.h"


UShopVehicle::UShopVehicle()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UShopVehicle::BeginPlay()
{
	Super::BeginPlay();

    if (ShopWidgetClass)
    {
        ShopWidget = CreateWidget<UShopWidget>(GetWorld(), ShopWidgetClass);
        ShopWidget->AddToViewport();
        ShopWidget->SetOwner(this);
    }


    if (!AvailableVehicles.IsEmpty())
    {
        for (TSubclassOf<AVehicle>& Vehicle : AvailableVehicles)
        {
            FVehicleOffer CatalogSlot;
            CatalogSlot.Vehicle = Vehicle;
            CatalogSlot.CatalogWidget = ShopWidget->CreateCatalogWidget(Vehicle);
            VehicleCatalog.Add(CatalogSlot);
        }
        SpawnVehicle(AvailableVehicles[0]);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Empty"));
    }
}

void UShopVehicle::SpawnVehicle(TSubclassOf<AVehicle> VehicleToSpawn)
{
    if (CurrentVehicle)
    {
        CurrentVehicle->Destroy();
    }
    if (MeshToAttach)
    {
        FActorSpawnParameters SpawnParameters;
        CurrentVehicle = GetWorld()->SpawnActor<AVehicle>(VehicleToSpawn, MeshToAttach->GetComponentLocation(), MeshToAttach->GetComponentRotation(), SpawnParameters);
        CurrentVehicle->GetMesh()->SetSimulatePhysics(false);
        CurrentVehicle->AttachToComponent(MeshToAttach, FAttachmentTransformRules::KeepRelativeTransform);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("NoMesh"));
    }
}
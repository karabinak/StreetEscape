// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

UInventory::UInventory()
{

	PrimaryComponentTick.bCanEverTick = false;


}


void UInventory::BeginPlay()
{
	Super::BeginPlay();

	
}


void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UInventory::AddToInventory(TSubclassOf<AVehicle> InVehicle)
{
	InventorySlots.Add(InVehicle);
	UE_LOG(LogTemp, Warning, TEXT("Vehicle Added"));
}


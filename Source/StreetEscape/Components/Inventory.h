// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "StreetEscape/Vehicle/VehicleStructs.h"
#include "Inventory.generated.h"

class AVehicle;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STREETESCAPE_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventory();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddToInventory(TSubclassOf<AVehicle> InVehicle);

protected:
	virtual void BeginPlay() override;

	

private:

	UPROPERTY(VisibleAnywhere, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<AVehicle>> InventorySlots;


public:	



		
};

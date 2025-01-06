// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StreetEscape/Data/OfferData.h"
#include "Shop.generated.h"

#define LOG_MISSINGCLASS(Message) UE_LOG(LogTemp, Warning, TEXT(Message))

//class AHideout;
//class AVehicle;
//class UVehicleOfferWidget;
class AHUDManager;
//class UShopWidget;
//class UInventory;

//USTRUCT(BlueprintType)
//struct FVehicleOffer
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere)
//	TSubclassOf<AVehicle> Vehicle;
//
//	UPROPERTY(VisibleAnywhere)
//	UVehicleOfferWidget* CatalogWidget;
//};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STREETESCAPE_API UShop : public UActorComponent
{
	GENERATED_BODY()

public:	
	UShop();

	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//void SpawnVehicle(TSubclassOf<AVehicle> VehicleToSpawn);

	UFUNCTION()
	void OnVehicleOfferClicked(FVehicleOffer VehicleOfferData);

	void OnBuyButtonPressed();



protected:
	virtual void BeginPlay() override;

	

private:


	//UPROPERTY(EditAnywhere)
	//TArray<TSubclassOf<AVehicle>> AvailableVehicles;

	UPROPERTY(EditAnywhere)
	TArray<FVehicleOffer> VehicleCatalog;

	UPROPERTY(EditAnywhere)
	AVehicle* CurrentVehicle;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AVehicle> CurrentVehicleClass;

	UPROPERTY()
	int32 CurrentVehiclePrice;

	//UPROPERTY(VisibleAnywhere)
	//UStaticMeshComponent* MeshToAttach;

	//// Widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> ShopWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> OfferWidgetClass;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	//UShopWidget* ShopWidget;


public:

	//FORCEINLINE void SetMeshToAttach(UStaticMeshComponent* InMeshToAttach) { MeshToAttach = InMeshToAttach; }
	//FORCEINLINE AVehicle* GetCurrentVehicle() { return CurrentVehicle; }
		
};

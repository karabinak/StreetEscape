// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"

class UCanvasPanel;
class UScrollBox;

class AVehicle;
class UShop;
class UVehicleOfferWidget;

UCLASS()
class STREETESCAPE_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//UFUNCTION()
	//UVehicleOfferWidget* CreateCatalogWidgets(TSubclassOf<AVehicle> InVehicle);

protected:
	virtual void NativeConstruct() override;

	//UFUNCTION()
	//void OnVehicleOfferClicked(TSubclassOf<AVehicle> Vehicle);

private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Canvas;

	UPROPERTY(meta = (BindWidget))
	UScrollBox* ScrollBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> VehicleCatalogClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TArray<UVehicleOfferWidget*> VehicleCatalogWidgets;

	UPROPERTY(VisibleAnywhere)
	UShop* Owner;


public:

	FORCEINLINE void InitializeWidget(UShop* InOwner) { Owner = InOwner; }
};

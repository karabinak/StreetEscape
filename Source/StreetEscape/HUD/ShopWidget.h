// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"

class AVehicle;
class UCanvasPanel;
class UVehicleOfferWidget;
class UScrollBox;
class AHideout;
class UShopVehicle;

UCLASS()
class STREETESCAPE_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	UVehicleOfferWidget* CreateCatalogWidget(TSubclassOf<AVehicle> InVehicle);

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnVehicleOfferClicked(TSubclassOf<AVehicle> Vehicle);

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
	UShopVehicle* Owner;



public:


	FORCEINLINE void SetOwner(UShopVehicle* InOwner) { Owner = InOwner; }
};

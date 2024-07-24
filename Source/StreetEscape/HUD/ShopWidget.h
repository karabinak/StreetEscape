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

UCLASS()
class STREETESCAPE_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;


private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Canvas;

	UPROPERTY(meta = (BindWidget))
	UScrollBox* ScrollBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> VehicleCatalogClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TArray<UVehicleOfferWidget*> VehicleCatalogWidgets;

public:

	UVehicleOfferWidget* CreateCatalogWidget(TSubclassOf<AVehicle> InVehicle, AHideout* InHideout);
};

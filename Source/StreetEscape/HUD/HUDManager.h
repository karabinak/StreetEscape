// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUDManager.generated.h"

//class UCustomizationWidget;
class UShopWidget;
class UOfferWidget;
class AHideout;

UENUM(BlueprintType)
enum class EWidgetState : uint8
{
	EWS_Shop UMETA(DisplayName = "Shop"),
	EWS_Customization UMETA(DisplayName = "Customization"),
	EWS_Gameplay UMETA(DisplayName = "Gameplay"),

	EWS_MAX UMETA(DisplayName = "Default")
};

UCLASS()
class STREETESCAPE_API AHUDManager : public AHUD
{
	GENERATED_BODY()

public:

	//void CreateMenuWidget(AHideout* InHideout);
	//void CreateShopWidget();

	void ChangeWidgetState(EWidgetState InWidgetState);

	//void ActiveGameplayWidgets();
	//void ActiveHideoutWidgets();
	//void DeactiveGameplayWidgets();
	//void DeactiveHideoutWidgets();

protected:
	virtual void BeginPlay() override;

	

private:
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	//AHideout* Hideout;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	EWidgetState WidgetState = EWidgetState::EWS_Shop;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	UShopWidget* ShopWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TArray<UOfferWidget*> VehicleOfferWidgets;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	//UCustomizationWidget* CustomizationWidget;

public:

	//FORCEINLINE void SetHideout(AHideout* InHideout) { Hideout = InHideout; }
	FORCEINLINE void SetShopWidget(UShopWidget* InShopWidget) { ShopWidget = InShopWidget; }
	FORCEINLINE void AddVehicleOfferWidget(UOfferWidget* InVehicleOfferWidget) { VehicleOfferWidgets.Add(InVehicleOfferWidget); }



	
};

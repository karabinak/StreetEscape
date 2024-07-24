// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUDManager.generated.h"

class UMenuWidget;
class UShopWidget;
class UVehicleOfferWidget;
class AHideout;

UENUM(BlueprintType)
enum class EWidgetState : uint8
{
	EWS_Hideout UMETA(DisplayName = "Hideout"),
	EWS_Gameplay UMETA(DisplayName = "Gameplay"),

	EWS_MAX UMETA(DisplayName = "Default")
};

UCLASS()
class STREETESCAPE_API AHUDManager : public AHUD
{
	GENERATED_BODY()

public:

	void CreateMenuWidget(AHideout* InHideout);
	void CreateShopWidget();

	void SetupWidgets(EWidgetState InWidgetState);

	void ActiveGameplayWidgets();
	void ActiveHideoutWidgets();
	void DeactiveGameplayWidgets();
	void DeactiveHideoutWidgets();

protected:
	virtual void BeginPlay() override;

	

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	AHideout* Hideout;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	EWidgetState WidgetState = EWidgetState::EWS_Hideout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> MenuWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	UMenuWidget* MenuWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> ShopWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	UShopWidget* ShopWidget;

public:

	FORCEINLINE void SetHideout(AHideout* InHideout) { Hideout = InHideout; }
	FORCEINLINE UShopWidget* GetShopWidget() { return ShopWidget; }



	
};

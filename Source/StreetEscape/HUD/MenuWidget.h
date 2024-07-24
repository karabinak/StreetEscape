// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

class UButton;
class AHideout;

UCLASS()
class STREETESCAPE_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnPlayButtonClicked();

	UFUNCTION()
	void OnShopButtonClicked();

private:

	UPROPERTY(meta = (BindWidget))
	UButton* PlayButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ShopButton;

	UPROPERTY(VisibleAnywhere)
	AHideout* Hideout;

public:

	void SetHideout(AHideout* InHideout) { Hideout = InHideout; }
};

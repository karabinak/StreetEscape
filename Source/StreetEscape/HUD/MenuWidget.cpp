// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "StreetEscape/Hideout/Hideout.h"
#include "HUDManager.h"

void UMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayButton->OnClicked.AddDynamic(this, &UMenuWidget::OnPlayButtonClicked);
	ShopButton->OnClicked.AddDynamic(this, &UMenuWidget::OnShopButtonClicked);
}

void UMenuWidget::OnPlayButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonClicked"));

	FLatentActionInfo LatentAction;
	UGameplayStatics::LoadStreamLevel(GetWorld(), FName(TEXT("Desert")), true, true, LatentAction);

	if (Hideout)
	{
		Hideout->SetLevel();
	}
}

void UMenuWidget::OnShopButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ShopClicked"));

	if (Hideout)
	{
		Hideout->InitializeWidgets();
	}
}

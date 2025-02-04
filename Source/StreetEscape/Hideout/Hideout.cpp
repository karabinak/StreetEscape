// Fill out your copyright notice in the Description page of Project Settings.

#include "Hideout.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "StreetEscape/Controller/VehicleController.h"
#include "StreetEscape/Components/Shop.h"
#include "StreetEscape/Components/Customization.h"

//#include "Blueprint/UserWidget.h"
//#include "StreetEscape/Vehicle/Vehicle.h"
//#include "StreetEscape/HUD/HUDManager.h"
//#include "StreetEscape/HUD/MenuWidget.h"


AHideout::AHideout()
{
	PrimaryActorTick.bCanEverTick = false;

	Shop = CreateDefaultSubobject<UShop>(TEXT("ShopComponent"));
	Customization = CreateDefaultSubobject<UCustomization>(TEXT("CustomizationComponent"));

	Hideout = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Hideout"));
	VehicleStand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_VehicleStand"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	SetRootComponent(Hideout);
	VehicleStand->SetupAttachment(GetRootComponent());
	SpringArm->SetupAttachment(GetRootComponent());
	Camera->SetupAttachment(SpringArm);
}

void AHideout::BeginPlay()
{
	Super::BeginPlay();

	//HUD = Cast<AHUDManager>(PC->GetHUD());
	PC = Cast<AVehicleController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PC)
	{
		// SET THIS ON RELEASE
		PC->SetViewTarget(this);
	}

}

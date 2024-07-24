// Fill out your copyright notice in the Description page of Project Settings.

#include "Hideout.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "StreetEscape/Controller/VehicleController.h"
#include "Kismet/GameplayStatics.h"
#include "StreetEscape/Vehicle/Vehicle.h"
#include "StreetEscape/HUD/HUDManager.h"
#include "StreetEscape/Components/ShopVehicle.h"
#include "StreetEscape/Components/CustomizationVehicle.h"


AHideout::AHideout()
{
	PrimaryActorTick.bCanEverTick = false;

	ShopVehicle = CreateDefaultSubobject<UShopVehicle>(TEXT("VehicleShop"));
	CustomizationVehicle = CreateDefaultSubobject<UCustomizationVehicle>(TEXT("VehicleCustomization"));

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

	ShopVehicle->SetHideout(this);
	
	PC = Cast<AVehicleController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	HUD = Cast<AHUDManager>(PC->GetHUD());

	if (PC)
	{
		PC->SetViewTarget(this);
		if (HUD)
		{
			HUD->SetHideout(this);
			HUD->CreateMenuWidget(this);
		}
	}
}

void AHideout::SpawnVehicle(TSubclassOf<AVehicle> VehicleToSpawn)
{
	if (CurrentVehicle)
	{
		CurrentVehicle->Destroy();
	}
	FActorSpawnParameters SpawnParameters;
	CurrentVehicle = GetWorld()->SpawnActor<AVehicle>(VehicleToSpawn, VehicleStand->GetComponentLocation(), VehicleStand->GetComponentRotation(), SpawnParameters);
	CurrentVehicle->GetMesh()->SetSimulatePhysics(false);
	CurrentVehicle->AttachToComponent(VehicleStand, FAttachmentTransformRules::KeepRelativeTransform);
}

void AHideout::InitializeWidgets()
{
	ShopVehicle->Initialize(HUD);
	//CustomizationVehicle->Initialize();
}

void AHideout::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHideout::SetLevel()
{
	if (CurrentVehicle && PC)
	{
		CurrentVehicle->GetMesh()->SetSimulatePhysics(true);
		CurrentVehicle->DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
		FViewTargetTransitionParams ViewTargetTransitionParams;
		ViewTargetTransitionParams.BlendTime = 1.5f;
		PC->SetViewTarget(CurrentVehicle, ViewTargetTransitionParams);
		PC->SetShowMouseCursor(false);
		PC->Possess(CurrentVehicle);

		HUD->SetupWidgets(EWidgetState::EWS_Gameplay);
	}
}


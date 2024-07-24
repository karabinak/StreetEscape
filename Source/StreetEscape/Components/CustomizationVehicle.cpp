// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationVehicle.h"


UCustomizationVehicle::UCustomizationVehicle()
{
	PrimaryComponentTick.bCanEverTick = true;


}

void UCustomizationVehicle::BeginPlay()
{
	Super::BeginPlay();

	
}


void UCustomizationVehicle::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


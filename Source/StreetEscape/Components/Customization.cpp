// Fill out your copyright notice in the Description page of Project Settings.


#include "Customization.h"


UCustomization::UCustomization()
{
	PrimaryComponentTick.bCanEverTick = true;


}

void UCustomization::BeginPlay()
{
	Super::BeginPlay();

	
}


//void UCustomization::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//}


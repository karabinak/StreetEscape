// Fill out your copyright notice in the Description page of Project Settings.


#include "Police.h"

#include "ChaosVehicleMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


#include "StreetEscape/Vehicle/Vehicle.h"

APolice::APolice()
{
	ArrestedZone = CreateDefaultSubobject<USphereComponent>("ArrestedZone");
	ArrestedZone->SetupAttachment(GetMesh());
}

void APolice::BeginPlay()
{
	Super::BeginPlay();

	ArrestedZone->OnComponentBeginOverlap.AddDynamic(this, &APolice::OverlappingWithPlayer);
	ArrestedZone->OnComponentEndOverlap.AddDynamic(this, &APolice::StopOverlappingWithPlayer);

	PlayerPawn = Cast<AVehicle>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->AddImpulse(GetActorForwardVector() * SpawnForce);

	GetWorld()->GetTimerManager().SetTimer(DistanceToPlayerTimer, this, &APolice::CheckPlayerDistance, 1.f, true, 2.f);
}

void APolice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APolice::OverlappingWithPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void APolice::StopOverlappingWithPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void APolice::CheckPlayerDistance()
{
	if (PlayerPawn)
	{
		FVector PlayerLocation = PlayerPawn->GetActorLocation();
		if (FVector::Dist(PlayerLocation, GetActorLocation()) >= DestroyDistance)
		{
			GetWorld()->GetTimerManager().ClearTimer(DistanceToPlayerTimer);
			Destroy();
		}
	}
}

void APolice::Steer(float AxisValue)
{
	GetVehicleMovement()->SetSteeringInput(AxisValue);
}

void APolice::Throttle(float AxisValue)
{
	GetVehicleMovement()->SetThrottleInput(AxisValue);
}

void APolice::Brake(float AxisValue)
{
	GetVehicleMovement()->SetBrakeInput(AxisValue);
}
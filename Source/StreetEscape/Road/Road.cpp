// Fill out your copyright notice in the Description page of Project Settings.


#include "Road.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "StreetEscape/Generator/Generator.h"


ARoad::ARoad()
{
	PrimaryActorTick.bCanEverTick = false;

	RoadMesh = CreateDefaultSubobject<UStaticMeshComponent>("RoadMesh");
	SpawnTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnerTrigger"));
	SetRootComponent(RoadMesh);
	SpawnTrigger->SetupAttachment(GetRootComponent());
}

void ARoad::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnTrigger->OnComponentBeginOverlap.AddDynamic(this, &ARoad::OnSpawnTriggerBegin);

	for (int i = 0; i < BuildingsToGenerate; i++)
	{
		UStaticMeshComponent* BuildingMesh = NewObject<UStaticMeshComponent>(this);

		BuildingMesh->SetupAttachment(GetRootComponent());

		if (!BuildingsMeshes.IsEmpty())
		{
			int32 RandomInt = FMath::RandRange(0, BuildingsMeshes.Num() - 1);
			BuildingMesh->SetStaticMesh(BuildingsMeshes[RandomInt]);
		}
		/*WOrk ON*/
		BuildingMesh->SetRelativeLocation(StartPos + FVector(Distance, 0.f, 0.f));
		if (i + 1 % 2 == BuildingsToGenerate / 2)
		{
			Distance *= -1;
		}


		BuildingMesh->RegisterComponent();
	}

}

void ARoad::OnSpawnTriggerBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor != UGameplayStatics::GetPlayerPawn(GetWorld(), 0)) return;

	SpawnTrigger->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Cast<AGenerator>(GetOwner())->CreateRoad();
}
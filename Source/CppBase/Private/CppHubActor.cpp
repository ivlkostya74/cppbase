// Fill out your copyright notice in the Description page of Project Settings.


#include "CppHubActor.h"
#include "TimerManager.h"
#include "CppBaseActor.h"
#include "Engine/World.h"



void ACppHubActor::OnTimeToSpawn()

{
	if (++CurrentTimerCount <= TotalCount)
	{
		const FVector Location = GetActorLocation() + FVector(FMath::FRandRange(200.0f, 1000.0f), FMath::FRandRange(200.0f, 1000.0f), 0.0f);
		const FRotator Rotation = FRotator::ZeroRotator;
		ACppBaseActor* SpawnedObject = GetWorld()->SpawnActor<ACppBaseActor>(CppClass, Location, Rotation);
		if (SpawnedObject)
		{
			SpawnedObjects.Add(SpawnedObject);
			UE_LOG(LogTemp, Log, TEXT("All spawned "));
		}
	}

	else
	{
		GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
		for (int i = TotalCount; i >= 1; --i)
		{
			UE_LOG(LogTemp, Log, TEXT(" objects destroyed"));
			GetWorldTimerManager().SetTimer(DestroyTimerHandle, this, &ACppHubActor::OnTimeToDestroy, DestroyTimerRate, true);
		}
	}
}
// ”ничтожает объекты по одному
void ACppHubActor::OnTimeToDestroy()
{
	if (!SpawnedObjects.IsEmpty())
	{


		SpawnedObjects.Top()->Destroy();

		SpawnedObjects.Pop();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DestroyTimerHandle);
		UE_LOG(LogTemp, Log, TEXT("All spawned objects destroyed"));
	}
}

// Sets default values
ACppHubActor::ACppHubActor()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ACppHubActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ACppHubActor::OnTimeToSpawn, 1, true);

	UE_LOG(LogTemp, Error, TEXT("World is null in ACppHubActor::BeginPlay"));

}


void ACppHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHubActor.generated.h"


class ACppBaseActor;

UCLASS()
class CPPBASE_API ACppHubActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category = "Timer Settings")
	float SpawnTimerRate = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Timer Settings")
	float DestroyTimerRate = 1.0f;

	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestroyTimerHandle;

	void OnTimeToSpawn();
	void OnTimeToDestroy();

	const int32 TotalCount = 10; 
	int32 CurrentTimerCount = 0; 
	
	//float TimerRate ; 

	UPROPERTY(EditAnywhere)
	TArray<ACppBaseActor*> SpawnedObjects;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<ACppBaseActor> CppClass;

public:	
	// Sets default values for this actor's properties
	ACppHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

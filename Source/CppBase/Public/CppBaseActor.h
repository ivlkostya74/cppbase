// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"




UENUM(BlueprintType)
enum class EMovementState :uint8
{
	Mobility,
	Static

};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	FVector CurrentLocation = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);


};


UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)

	FString PlayerName = "Netologiya"; 
	UPROPERTY(EditAnywhere)

	int EnemyNum = 20;
	UPROPERTY(EditDefaultsOnly)

	float CurrentHealth = 57.54687;
	UPROPERTY(EditInstanceOnly)

	bool IsAlive = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Amplitude = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Frequency = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector InitialLocation;
	
public:	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UFUNCTION(BlueprintCallable)
	void ShowInformation();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SinMovement();

private:
	



};

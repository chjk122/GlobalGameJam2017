// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "waveObj.h"
#include "GameFramework/Actor.h"
#include "WaveSpawner.generated.h"

UCLASS()
class WAVE_API AWaveSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	bool isActive = false;
	UPROPERTY(EditAnywhere)
	int levelNum;
	FVector loc;
	FRotator rotation;
	FActorSpawnParameters spawnParams;
	UWorld *world;

	// Sets default values for this actor's properties
	AWaveSpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void SpawnFourLegSpiral(float dt, float t);
	virtual void ThirtyTwoCircleHalfMidHalfFloor(float dt);
	virtual void EightCircleTwinSpiral(float dt, float t);
	virtual void PizzaSliceRotatingPulse(float dt, float t);
	virtual void Ring(float dt);
	virtual void LongPulseStarLines(float dt);
	virtual void TwinOval(float dt);

	UPROPERTY(EditDefaultsOnly, Category = "Our Spawning Object")
    TSubclassOf<AwaveObj> wave;
	
};

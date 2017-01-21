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
	// Sets default values for this actor's properties
	AWaveSpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditDefaultsOnly, Category = "Our Spawning Object")
    TSubclassOf<AwaveObj> wave;
	
};

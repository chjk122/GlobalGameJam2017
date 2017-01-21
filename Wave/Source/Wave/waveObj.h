// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "waveObj.generated.h"

UCLASS()
class WAVE_API AwaveObj : public AActor
{
	GENERATED_BODY()
	
public:
	float xDir;
	float yDir;
	// Sets default values for this actor's properties
	AwaveObj();

	virtual void Construct(float x, float y);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "Wave.h"
#include "WaveSpawner.h"
#include "waveObj.h"


// Sets default values
AWaveSpawner::AWaveSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaveSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
float count = 0;
void AWaveSpawner::Tick( float DeltaTime )
{
	count += DeltaTime;
	Super::Tick( DeltaTime );
	UWorld *world = GetWorld();
	if (count >= 1)
	{
		world->SpawnActor<AwaveObj>(AwaveObj::StaticClass());
		FVector scale = GetActorScale3D();
		scale.Z += 1;
		SetActorScale3D(scale);
		count = 0;
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "Wave.h"
#include "WaveSpawner.h"


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
float totalTime = 0;
void AWaveSpawner::Tick( float DeltaTime )
{
	count += DeltaTime;
	totalTime += DeltaTime;
	Super::Tick( DeltaTime );
	UWorld *world = GetWorld();
	if (count >= .05)
	{

		FVector loc = GetActorLocation();
		FActorSpawnParameters spawnParams;
		spawnParams.Owner = this;
		spawnParams.Instigator = Instigator;

		// spawn the object now 
		AwaveObj* waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, GetActorRotation(), spawnParams);
		waveSpawned->Construct(cosf(totalTime), sinf(totalTime));
		waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, GetActorRotation(), spawnParams);
		waveSpawned->Construct(cosf(totalTime + PI / 2), sinf(totalTime + PI / 2));
		waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, GetActorRotation(), spawnParams);
		waveSpawned->Construct(cosf(totalTime + PI), sinf(totalTime + PI));
		waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, GetActorRotation(), spawnParams);
		waveSpawned->Construct(cosf(totalTime + 3*PI / 2), sinf(totalTime + 3*PI / 2));
		count = 0;
	}
}


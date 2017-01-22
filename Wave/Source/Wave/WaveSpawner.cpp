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
	world = GetWorld();
	loc = GetActorLocation();
	rotation = GetActorRotation();
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
}

// Called every frame
float count = 0;
float totalTime = 0;
void AWaveSpawner::Tick( float DeltaTime )
{
	if (isActive)
	{
		count += DeltaTime;
		totalTime += DeltaTime;
		Super::Tick(DeltaTime);
		// 4 leg spiral
		if (levelNum == 1)
		{
			Ring(DeltaTime);
			TwinOval(DeltaTime);
		}
		if (levelNum == 2)
		{
			SpawnFourLegSpiral(DeltaTime, totalTime);
		}
		if (levelNum == 3)
		{
			LongPulseStarLines(DeltaTime);
		}
		if (levelNum == 4)
		{
			LongPulseStarLines(DeltaTime);
		}
		//SpawnFourLegSpiral(DeltaTime, totalTime);
		//ThirtyTwoCircleHalfMidHalfFloor(DeltaTime);
		//EightCircleTwinSpiral(DeltaTime, totalTime);
		//PizzaSliceRotatingPulse(DeltaTime, totalTime);
		//Ring(DeltaTime);
		//LongPulseStarLines(DeltaTime);
	}
}

float num1Count = 0;
void AWaveSpawner::SpawnFourLegSpiral(float dt, float t)
{
	if (num1Count < .05)
	{
		num1Count += dt;
		return;
	}
	AwaveObj* waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
	waveSpawned->Construct(cosf(t), sinf(t));
	waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
	waveSpawned->Construct(cosf(t + PI / 2), sinf(t + PI / 2));
	waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
	waveSpawned->Construct(cosf(t + PI), sinf(t + PI));
	waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
	waveSpawned->Construct(cosf(t + 3 * PI / 2), sinf(t + 3 * PI / 2));
	num1Count = 0;
}

float thirtyTwoTemp = 0;
float num2Count = 0;
void AWaveSpawner::ThirtyTwoCircleHalfMidHalfFloor(float dt)
{
	if (num2Count < 1)
	{
		num2Count += dt;
		return;
	}
	AwaveObj* waveSpawned;
	int max = 32;
	for (int x = 0; x < max; x++)
	{
		FVector tempLoc = loc;
		if (x % 2 == 0)
			tempLoc.Z += 100;
		waveSpawned = world->SpawnActor<AwaveObj>(wave, tempLoc, rotation, spawnParams);
		waveSpawned->Construct(cosf((x*PI) / (max/2) + thirtyTwoTemp), sinf(x*PI / (max / 2) + thirtyTwoTemp));
	}
	thirtyTwoTemp += 1.0 / (max/2);
	num2Count = 0;
}

float num3Count = 0;
void AWaveSpawner::EightCircleTwinSpiral(float dt, float t)
{
	if (num3Count < .075)
	{
		num3Count += dt;
		return;
	}
	AwaveObj* waveSpawned;
	int max = 4;
	for (int x = 0; x < max; x++)
	{
		waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
		waveSpawned->Construct(cosf(t + x * PI / 2 - PI / 32), -sinf(t + x * PI / 2 - PI / 32));
		waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
		waveSpawned->Construct(cosf(t + x * PI / 2 + PI / 32), sinf(t + x * PI / 2 + PI / 32));
	}
	num3Count = 0;
}

float num4Count = 0;
void AWaveSpawner::PizzaSliceRotatingPulse(float dt, float t)
{
	if (num4Count < .33)
	{
		num4Count += dt;
		return;
	}
	AwaveObj* waveSpawned;
	int max = 12;
	for (int x = 0; x < max; x+=2)
	{
		for (int y = 0; y < 6; y++)
		{
			waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
			waveSpawned->Construct(cosf(t / 3 + x * PI / 6 +  y*PI / 72), +sinf(t / 3 + x * PI / 6 + y*PI / 72));
		}
	}
	num4Count = 0;
}

float num5Count = 0;
void AWaveSpawner::Ring(float dt)
{
	if (num5Count < 1.8f)
	{
		num5Count += dt;
		return;
	}
	AwaveObj* waveSpawned;
	int max = 30;
	for (int x = 0; x < max; x++)
	{
		waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
		waveSpawned->Construct(cosf((x*PI) / (max / 2)), sinf(x*PI / (max / 2)));
	}
	num5Count = 0;
}

float num6Count = 0;
float timeOn = 0;
bool on = true;
void AWaveSpawner::LongPulseStarLines(float dt)
{
	if (!on)
	{
		if (num6Count >= 1)
		{
			on = true;
			num6Count = 0;
		}
		else
		{
			num6Count += dt;
			return;
		}
	}
	if (num6Count < .05f)
	{
		num6Count += dt;
		return;
	}
	AwaveObj* waveSpawned;
	int max = 16;
	FVector tempLoc = loc;
	tempLoc.Z += 100;
	for (int x = 0; x < max; x++)
	{
		waveSpawned = world->SpawnActor<AwaveObj>(wave, tempLoc, rotation, spawnParams);
		waveSpawned->Construct(cosf((x*PI) / (max / 2)), sinf(x*PI / (max / 2)));
	}
	num6Count = 0;
	timeOn += .1;
	if (timeOn >= 1)
	{
		on = false;
		timeOn = 0;
	}
}

float num7Count = 0;
void AWaveSpawner::TwinOval(float dt)
{
	if (num7Count < 1.55f)
	{
		num7Count += dt;
		return;
	}
	AwaveObj* waveSpawned;
	int max = 30;
	for (int x = 0; x < max; x++)
	{
		waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
		waveSpawned->Construct(cosf((x*PI) / (max / 2)), 2 * sinf(x*PI / (max / 2)));
	}
	for (int x = 0; x < max; x++)
	{
		waveSpawned = world->SpawnActor<AwaveObj>(wave, loc, rotation, spawnParams);
		waveSpawned->Construct(2 * cosf((x*PI) / (max / 2)), sinf(x*PI / (max / 2)));
	}
	num7Count = 0;
}
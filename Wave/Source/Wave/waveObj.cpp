// Fill out your copyright notice in the Description page of Project Settings.

#include "Wave.h"
#include "waveObj.h"


// Sets default values
AwaveObj::AwaveObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AwaveObj::BeginPlay()
{
	Super::BeginPlay();
	//bHidden = true;
	//FRotator rot = GetActorRotation();
	//FVector pos = GetActorLocation()

}

// Called every frame
void AwaveObj::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector scale = GetActorScale3D();
	scale.X += .1;
	scale.Y += .1;
	SetActorScale3D(scale);

}


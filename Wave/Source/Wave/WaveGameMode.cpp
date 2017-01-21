// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Wave.h"
#include "WaveGameMode.h"
#include "WaveCharacter.h"

AWaveGameMode::AWaveGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

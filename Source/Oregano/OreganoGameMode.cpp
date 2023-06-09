// Copyright Epic Games, Inc. All Rights Reserved.

#include "OreganoGameMode.h"
#include "OreganoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOreganoGameMode::AOreganoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

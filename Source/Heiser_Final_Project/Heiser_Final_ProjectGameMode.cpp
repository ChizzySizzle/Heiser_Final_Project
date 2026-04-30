// Copyright Epic Games, Inc. All Rights Reserved.

#include "Heiser_Final_ProjectGameMode.h"
#include "Heiser_Final_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHeiser_Final_ProjectGameMode::AHeiser_Final_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/My_Assets/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "PF_SkillTree_LFSGameMode.h"
#include "PF_SkillTree_LFSCharacter.h"
#include "UObject/ConstructorHelpers.h"

APF_SkillTree_LFSGameMode::APF_SkillTree_LFSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PF_SkillTree_LFS : ModuleRules
{
	public PF_SkillTree_LFS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

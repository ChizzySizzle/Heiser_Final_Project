// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Heiser_Final_Project : ModuleRules
{
	public Heiser_Final_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

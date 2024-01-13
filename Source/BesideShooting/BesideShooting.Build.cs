// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BesideShooting : ModuleRules
{
	public BesideShooting(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG", "AIModule" });

       
    }
}

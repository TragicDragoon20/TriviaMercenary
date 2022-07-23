// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TriviaMercenary : ModuleRules
{
	public TriviaMercenary(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

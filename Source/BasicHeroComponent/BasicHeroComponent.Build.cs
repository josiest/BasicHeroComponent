// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BasicHeroComponent : ModuleRules
{
    public BasicHeroComponent(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange( new [] {
            "Core",
            "CoreUObject",
            "Engine",
            "ModularGameplay",
            "EnhancedInput"
        });
    }
}

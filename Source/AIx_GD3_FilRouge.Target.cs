// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class AIx_GD3_FilRougeTarget : TargetRules
{
	public AIx_GD3_FilRougeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "AIx_GD3_FilRouge" } );
	}
}

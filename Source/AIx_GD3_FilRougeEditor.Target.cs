// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class AIx_GD3_FilRougeEditorTarget : TargetRules
{
	public AIx_GD3_FilRougeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "AIx_GD3_FilRouge" } );
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "CHLCleanWindowCommands.h"

#define LOCTEXT_NAMESPACE "FCHLCleanWindowModule"

void FCHLCleanWindowCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "CHLCleanWindow", "Bring up CHLCleanWindow window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE

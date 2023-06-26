// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "CHLCleanWindowStyle.h"

class FCHLCleanWindowCommands : public TCommands<FCHLCleanWindowCommands>
{
public:

	FCHLCleanWindowCommands()
		: TCommands<FCHLCleanWindowCommands>(TEXT("CHLCleanWindow"), NSLOCTEXT("Contexts", "CHLCleanWindow", "CHLCleanWindow Plugin"), NAME_None, FCHLCleanWindowStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};
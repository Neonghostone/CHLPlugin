// Copyright Epic Games, Inc. All Rights Reserved.

#include "CHLCleanWindow.h"
#include "CHLCleanWindowStyle.h"
#include "CHLCleanWindowCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

//Extra added libraries
#include "Widgets/Text/SMultiLineEditableText.h"


static const FName CHLCleanWindowTabName("CHLCleanWindow");

#define LOCTEXT_NAMESPACE "FCHLCleanWindowModule"

void FCHLCleanWindowModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FCHLCleanWindowStyle::Initialize();
	FCHLCleanWindowStyle::ReloadTextures();

	FCHLCleanWindowCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FCHLCleanWindowCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FCHLCleanWindowModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FCHLCleanWindowModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(CHLCleanWindowTabName, FOnSpawnTab::CreateRaw(this, &FCHLCleanWindowModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FCHLCleanWindowTabTitle", "CHLCleanWindow"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FCHLCleanWindowModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FCHLCleanWindowStyle::Shutdown();

	FCHLCleanWindowCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(CHLCleanWindowTabName);
}

TSharedRef<SDockTab> FCHLCleanWindowModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FCHLCleanWindowModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("CHLCleanWindow.cpp"))
		);

		FText CompileTextOptions = FText::Format(
			LOCTEXT("WindowWidgetText", "CHL Language: Scripting options"),
			FText::FromString(TEXT("FCHLCleanWindowModule::OnSpawnPluginTab")),
			FText::FromString(TEXT("CHLCleanWindow.cpp"))
		);

		FText CompileTextScripts = FText::Format(
			LOCTEXT("WindowWidgetText", "CHL Language: Run Scripts"),
			FText::FromString(TEXT("FCHLCleanWindowModule::OnSpawnPluginTab")),
			FText::FromString(TEXT("CHLCleanWindow.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(2)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(25)
				[
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					[
						SNew(STextBlock)
						.Text(CompileTextOptions)
					]

					+ SVerticalBox::Slot()
					[
						SNew(SButton)
						.Text(WidgetText)
						.ButtonColorAndOpacity(FColor(10, 255, 255, 255))
						.OnClicked_Raw(this, &FCHLCleanWindowModule::OnButtonCompileClicked)
					]

					+ SVerticalBox::Slot()
					[
						SNew(SButton)
						.Text(WidgetText)
						.ButtonColorAndOpacity(FColor(10, 255, 0, 255))
					]
				]
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(25)
				[
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					[
						SNew(STextBlock)
						.Text(CompileTextScripts)

					]

					+ SVerticalBox::Slot()
					[
						SNew(SMultiLineEditableText)
						.Text(WidgetText)
						.OnTextCommitted_Lambda([this](const FText& InText, ETextCommit::Type CommitType) { OnTextCommitted(InText); })
						.OnTextChanged_Lambda([this](const FText& InText) { OnTextChanged(InText); })
					]
				]
			]
		];
}

void FCHLCleanWindowModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(CHLCleanWindowTabName);
}

void FCHLCleanWindowModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FCHLCleanWindowCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FCHLCleanWindowCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}



//----------------------------------Assets widgets functions-----------------------------------------// 
void FCHLCleanWindowModule::OnTextCommitted(const FText& InText)
{
	//String conversion
	FText sForUse = FText::FromString("sItem.c_str()");
	FString SomeString = sForUse.ToString();
	SomeString = InText.ToString();

	UE_LOG(LogTemp, Warning, TEXT("From CHLCLeanWindow.cpp the text is: %s"), *SomeString);
	
}

void FCHLCleanWindowModule::OnTextChanged(const FText& InText)
{
	//String conversion
	FText sForUse = FText::FromString("sItem.c_str()");
	FString SomeString = sForUse.ToString();
	SomeString = InText.ToString();

	ActualScriptText = InText; 

	UE_LOG(LogTemp, Warning, TEXT("From CHLCLeanWindow.cpp the CHANGING text is: %s"), *SomeString);
} 

FReply FCHLCleanWindowModule::OnButtonCompileClicked()
{
	//String conversion
	FString ActualTextString = ActualScriptText.ToString();


	UE_LOG(LogTemp, Warning, TEXT("From CHLCLeanWindow.cpp the text is: %s"), *ActualTextString);

	return FReply::Handled();
}

void FCHLCleanWindowModule::RunScripts(FText pScriptText, int StartIndex)
{
	FText ScriptToConvertToString = pScriptText;
	FString SomeString = ScriptToConvertToString.ToString();
	FString LetterDetected;
	FString WordKeyWordDetected;

	UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin RUNNING SCRIPTS "));

	for (int32 i = 0; i < SomeString.Len(); ++i)//SomeString.Len() - 1
	{
		LetterDetected = *SomeString.Mid(i, 1);

		UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin LOOPOMNG %s"), *LetterDetected);

		if (LetterDetected.Equals(TEXT(" ")))
		{
			ProcessKeyWord(WordKeyWordDetected);
			//UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS COmplete word found %s"), WordKeyWordDetected[i] );
			return;
		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS THIS WORD PAWNS SPAWMING WORD IS!!!!!!!!!!!!!! %s"), SomeString[i]);
			WordKeyWordDetected.AppendChar(SomeString[i]);
		}
	}
}

void FCHLCleanWindowModule::ProcessKeyWord(FString pScriptWord)
{
	//UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS THIS WORD PAWNS SPAWMING WORD IS!!!!!!!!!!!!!! %s"), pScriptWord);
	UWorld* World = GEngine->GetWorldContexts()[0].World();
	FVector3d ActorSpawningPlaceLoc;
	FRotator ActorSpawningPlaceRot;

	ActorSpawningPlaceLoc.X = 10000.0f;
	ActorSpawningPlaceLoc.Y = 10000.0f;
	ActorSpawningPlaceLoc.Z = 10000.0f;

	ActorSpawningPlaceRot.Yaw = 0;
	ActorSpawningPlaceRot.Pitch = 0;
	ActorSpawningPlaceRot.Roll = 0;

	if (pScriptWord.Contains("Pawn"))
	{
		UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS THIS WORD PAWNS SPAWMING PAWN!!!!!!!!!!!!!!"));
		World->SpawnActor<AActor>(AActor::StaticClass(), ActorSpawningPlaceLoc, ActorSpawningPlaceRot);
		FString bpResource = "/Game/CHLPawnToTest.CHLPawnToTest";
		UBlueprint* GeneratedBP = Cast<UBlueprint>(StaticLoadObject(UObject::StaticClass(), NULL, *bpResource));
		//UWorld* World = GEngine->GetWorldContexts()[0].World();
		World->SpawnActor<AActor>(GeneratedBP->GeneratedClass, FVector(0, 0, 0), FRotator(0, 0, 0));
	}
}


//----------------------------------Assets widgets functions-----------------------------------------// 

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCHLCleanWindowModule, CHLCleanWindow)
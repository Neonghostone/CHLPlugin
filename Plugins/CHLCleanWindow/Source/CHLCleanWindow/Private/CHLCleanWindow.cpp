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
#include "AIController.h"
#include "Kismet/KismetStringLibrary.h"

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



	/* HOW TO GET ALL CLASSES AND THEN SPAWN SO 
	TArray<UClass*> ResultsOfSearch;
	TArray<TSharedPtr<FString>> ClassesListToChoose;
	//TSharedRef<IPropertyHandle> PropertyHandle; 
	DECLARE_DELEGATE_TwoParams(FOnTextCommitted, const FText&, ETextCommit::Type)
		//FString CurrentSelectedDeviceFamily;
		//PropertyHandle->GetValue(CurrentSelectedDeviceFamily);

		int CurrentSelectedIndex = 0;

	ResultsOfSearch = GetClasses(AGameModeBase::StaticClass());

	// better suggestions for a check are welcome
	for (int It = 0; It < ResultsOfSearch.Num(); ++It)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found class and class is %s"), *ResultsOfSearch[It]->GetName());
		ClassesListToChoose.Add(MakeShareable(new FString(*ResultsOfSearch[It]->GetName())));
	}
	*/
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
		LOCTEXT("WindowWidgetText", "Once there was pawn at 10 5 0"),
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

		FText CompileButtonLabel = FText::Format(
			LOCTEXT("WindowWidgetText", "Run Actual Scripts"),
			FText::FromString(TEXT("FCHLCleanWindowModule::OnSpawnPluginTab")),
			FText::FromString(TEXT("CHLCleanWindow.cpp"))
		);

		FText PlaceHolderButtonLabel = FText::Format(
			LOCTEXT("WindowWidgetText", "Clear"),
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
			.Padding(50)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(100)
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
						.Text(CompileButtonLabel)
						.ButtonColorAndOpacity(FColor(10, 255, 255, 255))
						.OnClicked_Raw(this, &FCHLCleanWindowModule::OnButtonCompileClicked)
					]

					+ SVerticalBox::Slot()
					[
						SNew(SButton)
						.Text(PlaceHolderButtonLabel)
						.ButtonColorAndOpacity(FColor(10, 255, 0, 255))
					]
				]
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(5)
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

	RunScripts(ActualScriptText, 0);

	return FReply::Handled();
}

void FCHLCleanWindowModule::RunScripts(FText pScriptText, int StartIndex)
{
	FText ScriptToConvertToString = pScriptText;
	FString SomeString = ScriptToConvertToString.ToString();
	FString LetterDetected;
	FString WordKeyWordDetected;

	UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin RUNNING SCRIPTS THE INDEX IS %i"), StartIndex );

	for (int32 i = StartIndex; i < SomeString.Len(); ++i)//SomeString.Len() - 1
	{
		LetterDetected = *SomeString.Mid(i, 1);

		UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin LOOPOMNG %s"), *LetterDetected);

		if (LetterDetected == " " )
		{
			ProcessKeyWord(WordKeyWordDetected, i);
			UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS COmplete word found %s"), *WordKeyWordDetected);
			UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS COmplete word found I index is %i"), i)
			WordKeyWordDetected.Empty(); 
			//return;
		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS THIS WORD PAWNS SPAWMING WORD IS!!!!!!!!!!!!!! %s"), SomeString[i]);
			WordKeyWordDetected.AppendChar(SomeString[i]);
		}
	}
}

void FCHLCleanWindowModule::ProcessKeyWord(FString pScriptWord, int pEndPos)
{
	TArray<FString> lPreWord; 
	TArray<FString> lPostWord;  

	//lPreWord = GetPreWordsOfKeyWord(pScriptWord, pEndPos);
	//lPostWord = GetPostWordsOfKeyWord(pScriptWord, pEndPos);

	if ( pScriptWord.Contains("Pawn") )
	{
		lPostWord = GetPostWordsOfKeyWord(pScriptWord, pEndPos);
		HandlePawnKeyword(lPreWord, lPostWord);
	}

	//RunScripts(ActualScriptText, pEndPos + 1);
}

//Desc: Neingho: This should check if is keyword? for sure? Not sure WIP 
void FCHLCleanWindowModule::HandleCheckIsIfKeywordTagKeyword(FString pKeyWord, TArray<FString> pPreWord, TArray<FString> pPostWord)
{

}

//Desc: Neingho: Gets the keywords before the keyword 
//*1: The keyword of it to know the number of indents to get next
TArray<FString> FCHLCleanWindowModule::GetPreWordsOfKeyWord(FString pKeyWord, int32 pStartingPosition)
{
	FText ScriptToConvertToString = ActualScriptText;
	FString ActualScriptString = ScriptToConvertToString.ToString();
	FString LetterDetected;
	FString WordDetected;
	TArray<FString> AllPreFinalWords;

	for (int32 i = pStartingPosition; i < ActualScriptString.Len() - pStartingPosition; ++i)//SomeString.Len() - 1
	{
		LetterDetected = *ActualScriptString.Mid(i, 1);

		if(LetterDetected == " ")
		{
			AllPreFinalWords.Add(WordDetected);
			WordDetected.Empty();
		}
		else
		{
			WordDetected.Append(LetterDetected);
		}
	}

	return AllPreFinalWords;
}

//Desc: Neingho: Gets the keywords after the keyword 
//*1: The keyword of it to know the number of indents to get next
TArray<FString> FCHLCleanWindowModule::GetPostWordsOfKeyWord(FString pKeyWord, int32 pStartingPosition)
{
	FText ScriptToConvertToString = ActualScriptText;
	FString ActualScriptString = ScriptToConvertToString.ToString();
	FString LetterDetected;
	FString WordDetected;
	TArray<FString> AllPostFinalWords;

	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST  %s"), *ActualScriptString);
	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST I start %i"), pStartingPosition);
	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST I  end %i"), ActualScriptString.Len() - pStartingPosition);
	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST I  ACtualScriptString length end %i"), ActualScriptString.Len());



	for (int32 i = pStartingPosition; i < ActualScriptString.Len(); ++i)//SomeString.Len() - 1
	{
		LetterDetected = *ActualScriptString.Mid(i, 1);
		UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST  LOOP %s"), *LetterDetected);
		UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST  LOOP I IS START %i"), pStartingPosition);
		UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST  LOOP THE END POS IS %i"), ActualScriptString.Len() - pStartingPosition);


		if (LetterDetected == " ")
		{
			if(WordDetected != "")
			{ 
				UE_LOG(LogTemp, Warning, TEXT("FROM GetPostWordsOfKeyWord Detecterd a keyword %s"), *WordDetected);
				AllPostFinalWords.Add(*WordDetected);
				UE_LOG(LogTemp, Warning, TEXT("FROM GetPostWordsOfKeyWord Detecterd a keyword length %i"), AllPostFinalWords.Num());
				WordDetected.Empty();
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FROM GetPostWordsOfKeyWord filling word!!!!!!!! %s"), *LetterDetected);
			WordDetected.Append(LetterDetected);
		}


	}

	UE_LOG(LogTemp, Warning, TEXT("FROM GetPostWordsOfKeyWord Final keywords are a keyword length %i"), AllPostFinalWords.Num());
	UE_LOG(LogTemp, Warning, TEXT("FROM GetPostWordsOfKeyWord Final keywords are a keyword first is %s"), *AllPostFinalWords[1]);
	return AllPostFinalWords;
}

//Desc: Neingho: Handles the pawn keyword 
//*1: The keyword of it to know the number of indents to get next
void FCHLCleanWindowModule::HandlePawnKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
	//UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS THIS WORD PAWNS SPAWMING WORD IS!!!!!!!!!!!!!! %s"), pScriptWord);
	UWorld* World = GEngine->GetWorldContexts()[0].World();
	FVector3d ActorSpawningPlaceLoc;
	FRotator ActorSpawningPlaceRot;
	AActor * PawnSpawned;
	AAIController * ForPawnAIController;
	int32 LengthOfKeywords = 0; 
	LengthOfKeywords = pPostWord.Num(); 

	UE_LOG(LogTemp, Warning, TEXT("FROM HandlePawnKeyword() post keywords are length %i"), pPostWord.Num());

	ActorSpawningPlaceLoc.X = 100.0f;//Not in use
	ActorSpawningPlaceLoc.Y = 100.0f;
	ActorSpawningPlaceLoc.Z = 0;


	//If is for vectors acces it
	if(pPostWord.Num() > 0)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("FROM HandlePawnKeyword() post keywords are KEYWORDS %s"), *pPostWord[0], *pPostWord[1], *pPostWord[2], *pPostWord[3]);

		if (pPostWord[0] == "at")
		{
			UE_LOG(LogTemp, Warning, TEXT("FROM HandlePawnKeyword() AT keyword detected NOW SETTING LOCATIONS"));

			ActorSpawningPlaceLoc.X = FCString::Atoi(*pPostWord[1]); 
			ActorSpawningPlaceLoc.Y = FCString::Atoi(*pPostWord[2]);
			ActorSpawningPlaceLoc.Z = FCString::Atoi(*pPostWord[3]); 

		}
	}




	ActorSpawningPlaceRot.Yaw = 0;//Not in use
	ActorSpawningPlaceRot.Pitch = 0;
	ActorSpawningPlaceRot.Roll = 0;
	
	UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS THIS WORD PAWNS SPAWMING PAWN!!!!!!!!!!!!!!"));
	FString bpResourcePawn = "/Game/CreativeHistoryLangangeContent/CHLPawnDefaultToTest.CHLPawnDefaultToTest";
	FString bpResourceAIController = "/Game/CreativeHistoryLangangeContent/CHLAIControllerMaxParTestBP.CHLAIControllerMaxParTestBP";
	UBlueprint* GeneratedBPPawn = Cast<UBlueprint>(StaticLoadObject(UObject::StaticClass(), NULL, *bpResourcePawn));
	UBlueprint* GeneratedBPAIController = Cast<UBlueprint>(StaticLoadObject(UObject::StaticClass(), NULL, *bpResourceAIController));
	PawnSpawned = World->SpawnActor<AActor>(GeneratedBPPawn->GeneratedClass, ActorSpawningPlaceLoc, FRotator(0, 0, 0));
	ForPawnAIController = World->SpawnActor<AAIController>(GeneratedBPAIController->GeneratedClass, ActorSpawningPlaceLoc, FRotator(0, 0, 0));
	APawn * PawnToCast = Cast<APawn>(PawnSpawned);
	AAIController * AIControllerToCast = Cast<AAIController>(ForPawnAIController);
	AIControllerToCast->Possess(PawnToCast);




	//AIControllerToCast->MoveTo(PawnToCast->GetActorLocation() + ActorSpawningPlaceLoc);
}

void FCHLCleanWindowModule::HandleAtKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{


}

void FCHLCleanWindowModule::HandleVectorKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{


}

void FCHLCleanWindowModule::HandleLocationKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{


}

void FCHLCleanWindowModule::HandleToKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{


}

//----------------------------------Assets widgets functions-----------------------------------------// 

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCHLCleanWindowModule, CHLCleanWindow)
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
#include "GameFramework/GameModeBase.h"
#include "MyWorldSubsystem.h"
#include "CHLMyEngineSubsystem.h"



/*   RESOURCES OF CODING
//if (GetWorld()->WorldType != EWorldType::Editor) to recognize the world you playing in
	 HOW TO GET ALL CLASSES AND THEN SPAWN SO
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

	//OnTestBeginPlay.Add( &FCHLCleanWindowModule::RegisterMenus) This one not good


	//MyMyWorldSubsystem->OnWorldBeginPlayCHL.AddDynamic(this, &FCHLCleanWindowModule::OnBeginPlayFunction );

	//GEngine->GetWorldContexts()[0].World()->OnWorldBeginPlay.AddRaw(this, &FCHLCleanWindowModule::OnBeginPlayFunction);

	//GEngine->GetCurrentPlayWorld()->OnWorldBeginPlay.AddRaw(this, &FCHLCleanWindowModule::OnBeginPlayFunction);

	//UClass * PawnToSpawnClass;

	//PawnToSpawnClass = World->GetAuthGameMode()->

	//World->GetAuthGameMode()->

	//class ABaseGameMode* myGameMode = (ABaseGameMode*)World->GetAuthGameMode();

	//PawnToSpawnClass = World->GetAuthGameMode()->DefaultPawnClass.GetDefaultObject();
	//UBlueprint* GeneratedBPPawn = World->GetAuthGameMode()->DefaultPawnClass.GetDefaultObject();

	//class APawn* PawnClassToSpawn = World->GetAuthGameMode()->DefaultPawnClass.GetDefaultObject();

	//class AVR_Pawn* myPawn = Cast<AVR_Pawn>(myGameMode->DefaultPawnClass.GetDefaultObject());
	//myGameMode->DefaultPawnClass;
	//myGameMode->DefaultPawnClass;
	//PawnToSpawnClass =
	//WORK IN PROGRESS KEEP FINDING THE PAWN

	//class AVR_Pawn* myPawn = Cast<AVR_Pawn>(myGameMode->DefaultPawnClass.GetDefaultObject());

*/


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
	MyMyWorldSubsystem = GEngine->GetWorldContexts()[0].World()->GetSubsystem<UMyWorldSubsystem>();
	MyMyWorldSubsystem->ReceiveTheModuleRef(this);

	//MyEngineSubsystem = GEngine->GetWorldContexts()[0].World()->GetSubsystem<UCHLMyEngineSubsystem>();
	MyEngineSubsystem = GEngine->GetEngineSubsystem<UCHLMyEngineSubsystem>();
	FText sForUse = FText::FromString("sItem.c_str()");
	FString StringFromText = sForUse.ToString();
	StringFromText = ActualScriptText.ToString();


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

//Neongho: to get called by delegate
void FCHLCleanWindowModule::OnBeginPlayFunction()
{
	UE_LOG(LogTemp, Warning, TEXT( "FROM CHLClean window This is a begin play from the whole game ************" ) );
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

TArray<ActionsPerActor> FCHLCleanWindowModule::CreateNewActionsForActor(AActor* ActorDoingAction, TArray<FString> pPreWords, TArray<FString> pPostWords, FString pKeyword, int32 pPreWordsI, int32 pPostWordsI)
{
	TArray<ActionsPerActor> LocalFinalActionsOnActor; 
	ActionsPerActor LocalActionPerActory;
	ActionOfStoryOfActor LocalActionStory; 
	FVector3d LocRellevantTowardsAction;
	//APawn * PawnGoingTo; 
	//int32 IndexOfKeyWordFinding; //should be used in various places

	//PawnGoingTo = Cast<APawn>(ActorDoingAction);

	//Now enter the actor spawned after wards create the array of actions then send it to engine subsystem
	UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions Number of I for where To is found or any other keyword %i"), pPostWordsI);

	//IndexOfKeyWordFinding = ChackInMountIfThereIsKW(pKeyword, pPostWords);  Left in here just in case

	//Like move to 
	if(pKeyword == "To")
	{ 
		UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions Number of I for where To is found or any other keyword ** %i"), 0 + pPostWordsI);

		if (pPostWords.Num() > 0 + pPostWordsI)
		{
			if (pPostWords.Num() > 1 + pPostWordsI)
			{
				UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions Number of I for where To is found or any other keyword TIER 1 ** %i"), 0 + pPostWordsI);
				LocRellevantTowardsAction.X = FCString::Atoi(*pPostWords[1 + pPostWordsI]);
			}
			if (pPostWords.Num() > 2 + pPostWordsI)
			{
				UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions Number of I for where To is found or any other keyword TIER 2 ** %i"), 0 + pPostWordsI);
				LocRellevantTowardsAction.Y = FCString::Atoi(*pPostWords[2 + pPostWordsI]);
			}
			if (pPostWords.Num() > 3 + pPostWordsI)
			{
				UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions Number of I for where To is found or any other keyword TIER 3 ** %i"), 0 + pPostWordsI);
				LocRellevantTowardsAction.Z = FCString::Atoi(*pPostWords[3 + pPostWordsI]);
			}

		}
	}

	LocalActionStory.KindOfStoryActionToDo = EN_MoveTo; 
	LocalActionStory.TimeToDoThatAction = 0.0f; 
	LocalActionStory.PointToGoOrElse = LocRellevantTowardsAction;

	LocalActionPerActory.ActorBindToAction = ActorDoingAction;
	LocalActionPerActory.ActionOfStoryOfActor.Add(LocalActionStory);

	LocalFinalActionsOnActor.Add(LocalActionPerActory);
	
	UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions final actions num is %i"), LocalFinalActionsOnActor.Num() );

	UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions final X of vec num is %f"), LocRellevantTowardsAction.X );
	UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions final Y of vec num is %f"), LocRellevantTowardsAction.Y );
	UE_LOG(LogTemp, Warning, TEXT("FROM CHLCLeanWindow.cpp CreateNewActionsForActor creating actions final Z of vec num is %f"), LocRellevantTowardsAction.Z );


	return LocalFinalActionsOnActor;
}


int32 FCHLCleanWindowModule::ChackInMountIfThereIsKW(FString KeywordSearchingFor, TArray<FString> KeyboardMount)
{
	for (int32 i = 0; i < KeyboardMount.Num(); i++)
	{
		if ( KeyboardMount[i].Contains(KeywordSearchingFor) )
		{
			UE_LOG(LogTemp, Warning, TEXT("FROM CHLCleanWindow the Index finally found is %i "), i);
			return i; 
		}
	}

	return -1;
}

bool FCHLCleanWindowModule::IsImportantKeyword(FString KeywordSearchingFor)
{

	if (KeywordSearchingFor.Contains("Pawn")) //|| true for later use or
	{
		UE_LOG(LogTemp, Warning, TEXT("FROM CHLCleanWindowCPP IsImportantKeyword end looking for key word")); 
		return true; 
	}

	return false;
}

void FCHLCleanWindowModule::OnTextCommitted(const FText& InText)
{
	//String conversion
	FText sForUse = FText::FromString("sItem.c_str()");
	FString SomeString = sForUse.ToString();
	SomeString = InText.ToString();

	UE_LOG(LogTemp, Warning, TEXT("From CHLCLeanWindow.cpp ios commited:"));
	//UE_LOG(LogTemp, Warning, TEXT("From CHLCLeanWindow.cpp ios commited: %s"), *SomeString);
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

//Desc: Neingho: Handles the pawn keyword 
FReply FCHLCleanWindowModule::OnButtonCompileClicked()
{

	RunScripts(ActualScriptText, 0);

	return FReply::Handled();
}

//Desc: Neongho: Handles the pawn keyword 
//*1: ScriptText The whole scripts and stuff
//*2: Start where to start
void FCHLCleanWindowModule::RunScripts(FText pScriptText, int StartIndex)
{
	FText ScriptToConvertToString = pScriptText;
	FString SomeString = ScriptToConvertToString.ToString();
	FString LetterDetected;
	FString WordKeyWordDetected;

	MyEngineSubsystem->PersistentScriptsText = SomeString;
	MyEngineSubsystem->PersistentScriptsTextV = pScriptText;

	//reset the actions once we click
	MyEngineSubsystem->ActionsToProcessOnLevelStart.Empty(); 
	
	for (int32 i = StartIndex; i < SomeString.Len(); ++i)//SomeString.Len() - 1
	{
		LetterDetected = *SomeString.Mid(i, 1);

		UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin LOOPOMNG %s"), *LetterDetected);

		if (LetterDetected == " " )
		{
			ProcessKeyWord(WordKeyWordDetected, i);
			//UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS COmplete word found %s"), *WordKeyWordDetected);
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

//Desc: Neongho: Handles the pawn keyword 
//*1: Script word the word processing then it checks if it is of a kind
void FCHLCleanWindowModule::ProcessKeyWord(FString pScriptWord, int pEndPos)
{
	TArray<FString> lPreWords;
	TArray<FString> lPostWords;

	//lPreWords = GetPreWordsOfKeyWord(pScriptWord, pEndPos); 
	//lPostWord = GetPostWordsOfKeyWord(pScriptWord, pEndPos);

	if ( pScriptWord.Contains("Pawn") )
	{
		lPostWords = GetPostWordsOfKeyWord(pScriptWord, pEndPos); //Should do prewords to WIP
		HandlePawnKeyword(lPreWords, lPostWords);
	}

	if (pScriptWord.Contains("Move"))
	{
		//lPostWords = GetPostWordsOfKeyWord(pScriptWord, pEndPos);
		//HandlePawnKeyword(lPreWords, lPostWords);
	}

	if (pScriptWord.Contains("To"))
	{
		//lPostWords = GetPostWordsOfKeyWord(pScriptWord, pEndPos);
		//HandleToKeyword(lPreWords, lPostWords);
	}

	//RunScripts(ActualScriptText, pEndPos + 1);
}

//Desc: Neongho: This should check if is keyword? for sure? Not sure WIP 
void FCHLCleanWindowModule::HandleCheckIsIfKeywordTagKeyword(FString pKeyWord, TArray<FString> pPreWord, TArray<FString> pPostWord)
{

}

//Desc: Neongho: Gets the keywords before the keyword WIP Post done but not pre
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

//Desc: Neongho: Gets the keywords after the keyword 
//*1: The keyword of it to know the number of indents to get next
TArray<FString> FCHLCleanWindowModule::GetPostWordsOfKeyWord(FString pKeyWord, int32 pStartingPosition)
{
	
	FText ScriptToConvertToString = ActualScriptText;
	FString ActualScriptString = ScriptToConvertToString.ToString();
	FString LetterDetected;
	FString WordDetected;
	TArray<FString> AllPostFinalWords;

	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST I start %i"), pStartingPosition);
	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST I  end  length %i"), ActualScriptString.Len() );

	
	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST  %s"), *ActualScriptString);
	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST I start %i"), pStartingPosition);
	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST I  end %i"), ActualScriptString.Len() - pStartingPosition);
	UE_LOG(LogTemp, Warning, TEXT("FROM Starting check of POST I  ACtualScriptString length end %i"), ActualScriptString.Len());


	if ( pStartingPosition+1 < ActualScriptString.Len() )
	{
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
					if (IsImportantKeyword(WordDetected))
					{
						return AllPostFinalWords;
					}


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
	}

	//UE_LOG(LogTemp, Warning, TEXT("FROM GetPostWordsOfKeyWord Final keywords are a keyword length %i"), AllPostFinalWords.Num());
	//UE_LOG(LogTemp, Warning, TEXT("FROM GetPostWordsOfKeyWord Final keywords are a keyword first is %s"), *AllPostFinalWords[1]); 
	return AllPostFinalWords;
}

//Desc: Neongho: Handles the pawn keyword 
//*1: The keyword of it to know the number of indents to get next
void FCHLCleanWindowModule::HandlePawnKeyword(TArray<FString> pPreWords, TArray<FString> pPostWords)
{
	//UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS THIS WORD PAWNS SPAWMING WORD IS!!!!!!!!!!!!!! %s"), pScriptWord);
	UWorld* World = GEngine->GetWorldContexts()[0].World();
	FVector3d ActorSpawningPlaceLoc;
	FRotator ActorSpawningPlaceRot;
	AActor * PawnSpawned;
	AAIController * ForPawnAIController;
	int32 LengthOfKeywords = 0; 
	LengthOfKeywords = pPostWords.Num();
	FText sForUse = FText::FromString("sItem.c_str()");
	FString StringFromText = sForUse.ToString();
	StringFromText = ActualScriptText.ToString();

	UE_LOG(LogTemp, Warning, TEXT("FROM HandlePawnKeyword() post keywords are length %i"), pPostWords.Num());

	ActorSpawningPlaceLoc.X = 100.0f;//Not in use text instead PLACEHOLDER
	ActorSpawningPlaceLoc.Y = 100.0f;
	ActorSpawningPlaceLoc.Z = 0;


	//If is for vectors acces it
	if(pPostWords.Num() > 0)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("FROM HandlePawnKeyword() post keywords are KEYWORDS %s"), *pPostWords[0], *pPostWords[1], *pPostWords[2], *pPostWords[3]);

		if (pPostWords[0].Contains("at"))
		{
			UE_LOG(LogTemp, Warning, TEXT("FROM HandlePawnKeyword() AT keyword detected NOW SETTING LOCATIONS"));

			ActorSpawningPlaceLoc.X = FCString::Atoi(*pPostWords[1]);
			ActorSpawningPlaceLoc.Y = FCString::Atoi(*pPostWords[2]);
			ActorSpawningPlaceLoc.Z = FCString::Atoi(*pPostWords[3]);
		}

	}

	ActorSpawningPlaceRot.Yaw = 0;//Not in use
	ActorSpawningPlaceRot.Pitch = 0;
	ActorSpawningPlaceRot.Roll = 0;
	
	//GeneratedBPPawn->GeneratedClass
	UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS THIS WORD PAWNS SPAWMING PAWN!!!!!!!!!!!!!!"));
	FString bpResourcePawn = "/Game/GOTA2/Blueprints/Characters/BP_GOTANumeriusOriginaInUsel.BP_GOTANumeriusOriginaInUsel"; ///Game/CreativeHistoryLangangeContent/CHLPawnDefaultToTest.CHLPawnDefaultToTest
	FString bpResourceAIController = "/Game/CreativeHistoryLangangeContent/CHLAIPluginNotGameAI.CHLAIPluginNotGameAI";
	UBlueprint* GeneratedBPPawn = Cast<UBlueprint>(StaticLoadObject(UObject::StaticClass(), NULL, *bpResourcePawn));
	UBlueprint* GeneratedBPAIController = Cast<UBlueprint>(StaticLoadObject(UObject::StaticClass(), NULL, *bpResourceAIController));
	PawnSpawned = World->SpawnActor<AActor>(GeneratedBPPawn->GeneratedClass, ActorSpawningPlaceLoc, FRotator(0, 0, 0));
	ForPawnAIController = World->SpawnActor<AAIController>(GeneratedBPAIController->GeneratedClass, ActorSpawningPlaceLoc, FRotator(0, 0, 0));
	APawn * PawnToCast = Cast<APawn>(PawnSpawned);
	AAIController * AIControllerToCast = Cast<AAIController>(ForPawnAIController);
	AIControllerToCast->Possess(PawnToCast);

	//Make a foreach here to check which is the To keyword and from there process it somehow
	if( pPostWords.Num() > 4 )
	{
		if ( ChackInMountIfThereIsKW("To", pPostWords) > 0 )
		{
			UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS PAWN CREATING ITS ACTIONS FOR TO word "));                                                  
			MyEngineSubsystem->ActionsToProcessOnLevelStart.Append( CreateNewActionsForActor(PawnSpawned, pPreWords, pPostWords, "To", 0, ChackInMountIfThereIsKW("To", pPostWords)));
			UE_LOG(LogTemp, Warning, TEXT("FROM CHLPlugin THIS HAS PAWN CREATING ITS ACTIONS FOR TO word FINAL NUM IS %i"), MyEngineSubsystem->ActionsToProcessOnLevelStart.Num() );
		}
	}

	if ( GEngine->GetEngineSubsystemBase(UMyWorldSubsystem::StaticClass()) != nullptr )
	{
		UE_LOG(LogTemp, Warning, TEXT(" FROM Spawn plugin chl windowHello WorldSubsystem Is Is not a null ptr")); 
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" FROM Spawn plugin chl windowHello WorldSubsystem IS a null ptr"));
	}

}

//Desc: Neongho: Prossed and PreWord in other places
void FCHLCleanWindowModule::HandleAtKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
	UE_LOG(LogTemp, Warning, TEXT(" FROM Spawn plugin chl KEYWORD DETECTED *************** AT "));

}

//Desc: Neongho: Location then it is always a vector for sure NOT IN USE NOT USEFUL AT FIRST*
void FCHLCleanWindowModule::HandleVectorKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
	UE_LOG(LogTemp, Warning, TEXT(" FROM Spawn plugin chl KEYWORD DETECTED *************** Vector "));

}

//Desc: Neongho: Location then it is always a vector for sure
void FCHLCleanWindowModule::HandleLocationKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
	UE_LOG(LogTemp, Warning, TEXT(" FROM Spawn plugin chl KEYWORD DETECTED *************** Location "));

}

//Desc: Neongho: Move to a specific place used after move to IT IS PREFIX OR POSTFIX SO... added somehwere else
void FCHLCleanWindowModule::HandleToKeyword(TArray<FString> pPreWord, TArray<FString> pPostWord)
{
	UE_LOG(LogTemp, Warning, TEXT(" FROM Spawn plugin chl KEYWORD DETECTED *************** To "));
	//CreateNewActionsForActor("To");
}

//Desc: Neongho: True is vector false is float SHOULD BE ENUM AFTER "AT"
bool bIsVectorOrFloat(FString StringEntering)
{
	return true; 
}

//----------------------------------Assets widgets functions-----------------------------------------// 

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCHLCleanWindowModule, CHLCleanWindow)
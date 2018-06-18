// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "RenovaTest1GameMode.h"
#include "RenovaTest1PlayerController.h"
#include "RenovaTest1Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void ARenovaTest1GameMode::BeginPlay()
{
	Super::BeginPlay();

	ARenovaTest1Character* MyCharacter = Cast<ARenovaTest1Character>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (PlayerHUDClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

ARenovaTest1GameMode::ARenovaTest1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARenovaTest1PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
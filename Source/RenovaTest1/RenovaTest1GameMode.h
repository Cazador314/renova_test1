// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RenovaTest1GameMode.generated.h"

UCLASS(minimalapi)
class ARenovaTest1GameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override; //Override beginplay from the base class


public:
	ARenovaTest1GameMode();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Timer", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY()
		class UUserWidget* CurrentWidget;
};




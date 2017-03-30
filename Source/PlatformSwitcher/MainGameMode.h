// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMSWITCHER_API AMainGameMode : public AGameMode
{
	GENERATED_BODY()
	

public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void OnSwitch();

	bool Switched;
	
};

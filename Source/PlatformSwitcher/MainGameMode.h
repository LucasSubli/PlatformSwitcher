// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
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

	void OnRestart();

	void OnGameOver(bool Win);

	UFUNCTION(BlueprintCallable, Category = "UMG Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	bool Switched;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	TSubclassOf<UUserWidget> StartingWindgetClass;

	UPROPERTY()
	UUserWidget* CurrentWidget;
	
};

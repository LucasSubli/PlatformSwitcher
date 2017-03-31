// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformSwitcher.h"
#include "MainGameMode.h"
#include "GameWidget.h"




void AMainGameMode::BeginPlay() {
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Switch", IE_Pressed, this, &AMainGameMode::OnSwitch);
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Restart", IE_Pressed, this, &AMainGameMode::OnRestart).bExecuteWhenPaused = true;

	ChangeMenuWidget(StartingWindgetClass);

	((UGameWidget*)CurrentWidget)->Load();
}

void AMainGameMode::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AMainGameMode::OnSwitch() {

	auto PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	FVector NewLocation =PlayerCharacter->GetActorLocation();

	if (Switched) {
		
		NewLocation.X = 1200.0f;
		PlayerCharacter->SetActorLocation(NewLocation);

	} else {
		NewLocation.X = 200.0f;
		PlayerCharacter->SetActorLocation(NewLocation);
	}

	Switched = !Switched;
}


void AMainGameMode::OnRestart() {
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void AMainGameMode::OnGameOver(bool Win) {

	UGameplayStatics::SetGamePaused(GetWorld(), true);
	((UGameWidget*)CurrentWidget)->OnGameOver(Win);

}

void AMainGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass) {

	if (CurrentWidget != nullptr) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr) {
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr) {
			CurrentWidget->AddToViewport();
		}
	}
}

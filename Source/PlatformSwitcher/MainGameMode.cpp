// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformSwitcher.h"
#include "MainGameMode.h"




void AMainGameMode::BeginPlay() {
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Switch", IE_Pressed, this, &AMainGameMode::OnSwitch);
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
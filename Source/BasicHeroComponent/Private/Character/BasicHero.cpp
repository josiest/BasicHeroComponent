// Copyright 2024 Josie Thompson, MIT License
#include "Character/BasicHero.h"
#include "Components/BasicHeroComponent.h"
#include "EnhancedInputComponent.h"


// Sets default values
ABasicHero::ABasicHero(const FObjectInitializer& ObjectInitializer)
	: Super{ ObjectInitializer }
{
	HeroComponent = CreateDefaultSubobject<UBasicHeroComponent>(TEXT("HeroComponent"));
}

// Called to bind functionality to input
void ABasicHero::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		HeroComponent->SetupPlayerInput(EnhancedInputComponent);
	}
}


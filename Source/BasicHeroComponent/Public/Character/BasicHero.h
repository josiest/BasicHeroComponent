// Copyright 2024 Josie Thompson, MIT License

#pragma once
#include "GameFramework/Character.h"
#include "BasicHero.generated.h"

class UBasicHeroComponent;

UCLASS()
class BASICHEROCOMPONENT_API ABasicHero : public ACharacter {
	GENERATED_BODY()

public:
	ABasicHero(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent * PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBasicHeroComponent> HeroComponent;
};

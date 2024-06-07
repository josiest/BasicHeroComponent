// Copyright 2024 Josie Thompson, MIT License
#include "Components/BasicHeroComponent.h"

// #include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

UBasicHeroComponent::UBasicHeroComponent(const FObjectInitializer& ObjectInitializer)
	: Super{ ObjectInitializer }
{
}

void UBasicHeroComponent::SetupPlayerInput(UEnhancedInputComponent * InputComponent)
{
	const auto* Controller = GetController<APlayerController>();
	check(Controller);

	const auto Player = Controller->GetLocalPlayer();
	check(Player);

	using UInputSystem = UEnhancedInputLocalPlayerSubsystem;
	if (auto* InputSystem = Player->GetSubsystem<UInputSystem>()) {
		InputSystem->AddMappingContext(InputContext, ContextPriority);
	}
	InputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	InputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
}

void UBasicHeroComponent::Move(const FInputActionValue & Value)
{
	auto* Pawn = GetPawn<APawn>();
    if (!Pawn || !Value.IsNonZero()) { return; }

    const auto MovementVector = Value.Get<FVector2d>();
    const FRotator MovementRotation{ 0., Pawn->GetControlRotation().Yaw, 0. };

    if (MovementVector.X != 0.) {
        const auto RightDirection = MovementRotation.RotateVector(FVector::RightVector);
        Pawn->AddMovementInput(RightDirection, MovementVector.X);
    }

    if (MovementVector.Y != 0.) {
        const auto ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
        Pawn->AddMovementInput(ForwardDirection, MovementVector.Y);
    }
}

void UBasicHeroComponent::Look(const FInputActionValue & Value)
{
	auto* Pawn = GetPawn<APawn>();
    const auto LookVector = Value.Get<FVector2d>();
    if (LookVector.X != 0.) {
        Pawn->AddControllerYawInput(LookVector.X);
    }
    if (LookVector.Y != 0.) {
        Pawn->AddControllerPitchInput(LookVector.Y);
    }
}

// Copyright 2024 Josie Thompson, MIT License
#pragma once
#include "Components/PawnComponent.h"
#include "BasicHeroComponent.generated.h"

class UInputAction;
class UInputMappingContext;
class UEnhancedInputComponent;
struct FInputActionValue;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BASICHEROCOMPONENT_API UBasicHeroComponent : public UPawnComponent {
	GENERATED_BODY()

public:
	UBasicHeroComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void SetupPlayerInput(UEnhancedInputComponent* InputComponent);
	
	/** Tell the MovementComponent how to move when given movement input */
	void Move(const FInputActionValue& Value);
	
	/** Tell the MovementComponent how to control the camera when given camera input */
	void Look(const FInputActionValue& Value);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	TObjectPtr<UInputMappingContext> InputContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	int ContextPriority = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	TObjectPtr<UInputAction> LookAction;
};

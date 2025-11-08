// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Soldier.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class OPTIMIZESHOOTER_API ASoldier : public ACharacter
{
	GENERATED_BODY()

public:
	ASoldier();

	virtual void Tick(float DeltaTime) override;

	/** Inputs **/
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Move(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;

	void InitializeMappingContext();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* CharacterMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

};

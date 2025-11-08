// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Soldier.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ASoldier::ASoldier()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASoldier::BeginPlay()
{
	Super::BeginPlay();

	InitializeMappingContext();
}

void ASoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASoldier::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASoldier::Move);
	}
}

void ASoldier::InitializeMappingContext()
{
	APlayerController* PlayerController = Cast<APlayerController>(Controller);

	if (PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CharacterMappingContext, 0);
		}
	}
}

void ASoldier::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	UE_LOG(LogTemp, Warning, TEXT("Movement Vector: X=%f, Y=%f"), MovementVector.X, MovementVector.Y);

	if (Controller)
	{
		const FVector ForwardDirection = GetActorForwardVector();
		AddMovementInput(ForwardDirection, MovementVector.Y);

		const FVector RightDirection = GetActorRightVector();
		AddMovementInput(RightDirection, MovementVector.X);
	}
}


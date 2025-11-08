// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Soldier.h"

ASoldier::ASoldier()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASoldier::BeginPlay()
{
	Super::BeginPlay();	
}

void ASoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASoldier::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


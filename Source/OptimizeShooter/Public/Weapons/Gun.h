// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class UStaticMeshComponent;

UCLASS()
class OPTIMIZESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	AGun();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* GunMesh;
};

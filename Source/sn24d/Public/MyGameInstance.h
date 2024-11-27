// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SN24D_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "HealthPotion")
	int32 CreditCost;

	UPROPERTY(EditAnywhere)
	UStaticMesh* mesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> actor;

	UPROPERTY(EditAnywhere)
	UMaterial* mat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString text;

};

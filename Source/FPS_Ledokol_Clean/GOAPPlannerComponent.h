// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GOAPAction.h"
#include "GOAPPlannerComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPS_LEDOKOL_CLEAN_API UGOAPPlannerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UGOAPPlannerComponent();

    /**
     * Главная функция планировщика (алгоритм A*).
     */
    UFUNCTION(BlueprintCallable, Category = "GOAP AI")
    bool BuildPlan(
        const TMap<FGameplayTag, bool>& CurrentWorldState,
        const TMap<FGameplayTag, bool>& GoalState,
        const TArray<UGOAPAction*>& AvailableActions,
        TArray<UGOAPAction*>& OutPlan
    );
};
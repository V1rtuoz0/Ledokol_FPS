// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimMontage.h"
#include "Engine/DataAsset.h"
#include "GOAPAction.generated.h"

// Перечисление 3 состояний FSM по Джеффу Оркину (F.E.A.R.)
UENUM(BlueprintType)
enum class EGOAPState : uint8
{
    Goto            UMETA(DisplayName = "Goto (Move)"),
    Animate         UMETA(DisplayName = "Animate (Attack/Reload/Dodge)"),
    UseSmartObject  UMETA(DisplayName = "Use Smart Object")
};

/**
 * Базовый класс карточки действия для GOAP планировщика.
 */
UCLASS(Blueprintable, BlueprintType)
class FPS_LEDOKOL_CLEAN_API UGOAPAction : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    // Название действия для отладки
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GOAP")
    FName ActionName;

    // Базовый вес (cost) для алгоритма A* (меньше = приоритетнее)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GOAP")
    float BaseCost = 1.0f;

    // Предварительные условия (Preconditions)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GOAP")
    TMap<FGameplayTag, bool> Preconditions;

    // Эффекты (Effects)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GOAP")
    TMap<FGameplayTag, bool> Effects;

    // Состояние FSM для StateTree
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GOAP")
    EGOAPState TargetFSMState = EGOAPState::Animate;

    // Ссылка на анимационный монтаж
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GOAP|Payload")
    UAnimMontage* ActionMontage = nullptr;
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "GOAPPlannerComponent.h"
#include "GOAPAction.h"

UGOAPPlannerComponent::UGOAPPlannerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UGOAPPlannerComponent::BuildPlan(
	const TMap<FGameplayTag, bool>& CurrentWorldState,
	const TMap<FGameplayTag, bool>& GoalState,
	const TArray<UGOAPAction*>& AvailableActions,
	TArray<UGOAPAction*>& OutPlan)
{
	OutPlan.Empty();

	for (UGOAPAction* Action : AvailableActions)
	{
		if (!IsValid(Action))
		{
			continue;
		}

		bool bMatchesGoal = false;
		for (const auto& GoalPair : GoalState)
		{
			if (Action->Effects.Contains(GoalPair.Key) && Action->Effects[GoalPair.Key] == GoalPair.Value)
			{
				bMatchesGoal = true;
				break;
			}
		}

		if (bMatchesGoal)
		{
			OutPlan.Add(Action);
			return true;
		}
	}

	return false;
}

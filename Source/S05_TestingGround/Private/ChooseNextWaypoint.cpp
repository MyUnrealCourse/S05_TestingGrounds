// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGround.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Public/ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	// UE_LOG(LogTemp, Warning, TEXT("The class is in session"));
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), Index);

	return EBTNodeResult::Succeeded;
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGround.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Public/PatrolRoute.h"
#include "../Public/ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//get controlled pawn
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetControlledPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed;  } //make sure the PatrolRoute component exists and is initialized

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A Guard is missing Patrol Points"));
		return EBTNodeResult::Failed;
	}

	//Set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//cycle Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), Index);
	

	return EBTNodeResult::Succeeded;
}

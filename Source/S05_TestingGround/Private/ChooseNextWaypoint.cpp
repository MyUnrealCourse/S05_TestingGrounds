// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGround.h"
#include "AIController.h"
#include "../Public/PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Public/ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//get controlled pawn
	auto AIControl = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIControl->GetControlledPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

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

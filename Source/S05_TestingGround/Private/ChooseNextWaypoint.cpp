// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGround.h"
#include "ChooseNextWaypoint.h"
#include "../Public/ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("The class is in session"));
	
	return EBTNodeResult::Succeeded;
}

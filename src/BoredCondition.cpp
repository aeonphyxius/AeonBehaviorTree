#include "BoredCondition.h"

using namespace AeonBehaviorTree;

BoredCondition::BoredCondition(std::string name) : ConditionNode(name)
{
	SetNodeState(IDLE);
}



void BoredCondition::Execute(BlackBoard * black_board)
{	
	SetNodeState(
		black_board->entity->IsBored(black_board->ticks) ? SUCCESS : FAILURE
		);
}
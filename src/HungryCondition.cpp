#include "HungryCondition.h"

using namespace AeonBehaviorTree;

HungryCondition::HungryCondition(std::string name) : ConditionNode(name)
{
	SetNodeState(IDLE);
}



void HungryCondition::Execute(BlackBoard * black_board)
{
	SetNodeState(
		black_board->entity->IsHungry() ? SUCCESS : FAILURE
		);
}
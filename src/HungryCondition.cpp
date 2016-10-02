#include "HungryCondition.h"
#include "Utils.h"
using namespace AeonBehaviorTree;

HungryCondition::HungryCondition(std::string name) : ConditionNode(name)
{
	SetNodeState(IDLE);
}

void HungryCondition::Execute(std::shared_ptr<BlackBoard> black_board)
{
	Utils::Log("-- HungryCondition : ", name, " Execute");
	SetNodeState( black_board->entity->IsHungry() ? SUCCESS : FAILURE );
}
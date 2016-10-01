#include "EatAction.h"

using namespace AeonBehaviorTree;

EatAction::EatAction(std::string name) : ActionNode(name)
{
	SetNodeState(IDLE);
}

EatAction::~EatAction()
{	
}

void EatAction::Execute(BlackBoard * black_board)
{
	black_board->entity->Eat(black_board->ticks);
	SetNodeState(SUCCESS);
}
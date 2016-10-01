#include "EatAction.h"
#include "Utils.h"

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
	Utils::Log("-- EatAction : ", name, " Execute");
	black_board->entity->Eat();
	SetNodeState(SUCCESS);
}
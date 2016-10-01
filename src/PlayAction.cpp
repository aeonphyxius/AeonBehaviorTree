#include "PlayAction.h"
#include "Utils.h"

using namespace AeonBehaviorTree;

PlayAction::PlayAction(std::string name) : ActionNode(name)
{	
	SetNodeState(IDLE);
}

void PlayAction::Execute(BlackBoard * black_board)
{
	Utils::Log("-- PlayAction : ", name, " Execute");
	black_board->entity->Play(black_board->ticks);
	SetNodeState(SUCCESS);
}
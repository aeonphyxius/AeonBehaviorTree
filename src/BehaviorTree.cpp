#include "BehaviorTree.h"
#include "Utils.h"

using namespace AeonBehaviorTree;

BehaviorTree::BehaviorTree():
	root(nullptr)
{

}

BehaviorTree::~BehaviorTree()
{
	root = nullptr;
}

void BehaviorTree::AddRootNode(ControlNode * new_root_node)
{
	root = new_root_node;
}

void BehaviorTree::Execute(Entity * entity, BlackBoard * black_board)
{
	Utils::Log("Start Behavior Tree!");

	if (root == nullptr)
	{
		Utils::Log("A root node should be assigned before executing the BT !");
		return;
	}

	if (entity == nullptr)
	{
		Utils::Log("An entity is needed to execute the BT !");
		return;
	}
	black_board->entity = entity;
	black_board->ticks = 0.0f;

	if (black_board == nullptr)
	{
		black_board = new BlackBoard();
		Utils::Log("BlackBoard was null, creating a new one !");		
	}


	while (true)
	{
		Utils::Log("Ticking the root node !");
		++ black_board->ticks;
		
		Utils::Log("Execute");
		root->Execute(black_board);
				
		if (root->GetNodeState() != RUNNING)
		{
			Utils::Log("Execution ended :)");
			return;
		}
	}

}

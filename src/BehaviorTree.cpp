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

void BehaviorTree::AddRootNode(std::shared_ptr<ControlNode> new_root_node)
{
	root = new_root_node;
}

void BehaviorTree::Execute(std::shared_ptr<Entity> entity, std::shared_ptr<BlackBoard> black_board)
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
		Utils::Log("BlackBoard was null, exiting ... !");		
		return;
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


void BehaviorTree::Execute(std::vector <EntitySharedPtr> &entites, std::vector <BlackBoardSharedPtr> &black_boards, std::vector <ControlNode*> &roots)
{	
	bool isEnded = false;
	Utils::Log("Start Behavior Tree!");

	if (roots.empty())
	{
		Utils::Log("A root node should be assigned before executing the BT !");
		return;
	}

	if (entites.empty())
	{
		Utils::Log("An entity is needed to execute the BT !");
		return;
	}
	

	if (black_boards.empty())
	{
		black_boards = std::vector <BlackBoardSharedPtr>();
		for (unsigned int i = 0; i < entites.size(); ++i)
		{
			black_boards.push_back(std::unique_ptr<BlackBoard>());
		}
		Utils::Log("BlackBoard was null, creating a new one !");
	}

	for (unsigned int i = 0; i < black_boards.size(); ++i)
	{
		black_boards[i]->ticks = 0.0f;
		black_boards[i]->entity = entites[i];
	}
		


	while (true)
	{
		Utils::Log("Ticking the root node !");
		for (unsigned int i = 0; i < black_boards.size(); ++i)
			++black_boards[i]->ticks;

		Utils::Log("Execute");
		isEnded = true;
		for (unsigned int i = 0; i < black_boards.size(); ++i)
		{
			roots[i]->Execute(black_boards[i]);
			if (roots[i]->GetNodeState() != RUNNING && isEnded)
				isEnded = true;
			else
				isEnded = false;
		}
		
		if (isEnded)
		{
			Utils::Log("Execution ended :)");
			return;
		}
	}
}


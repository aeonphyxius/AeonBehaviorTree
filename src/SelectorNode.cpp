#include "SelectorNode.h"
#include "Utils.h"
using namespace AeonBehaviorTree;

SelectorNode::SelectorNode(std::string name) : ControlNode(name)
{
}

SelectorNode::~SelectorNode() {}

void SelectorNode::Execute(BlackBoard * black_board)
{
	Utils::Log("-- SelectorNode : ", name, " Execute");
	if (child_nodes.size() == 0)
	{
		SetNodeState(SUCCESS);
		Utils::Log("-- SelectorNode Node: ", name, " returning ", SUCCESS, " (no childs to iterate)!");
		return;
	}

	if (GetNodeState() != RUNNING)
	{
		SetNodeState(RUNNING);
		current = 0;
	}	

	if (child_nodes[current]->GetNodeState() == IDLE ||
		child_nodes[current]->GetNodeState() == RUNNING)
	{
		child_nodes[current]->Execute(black_board);
	}

	if (child_nodes[current]->GetNodeState() == SUCCESS)
	{
		SetNodeState(FAILURE);
		Utils::Log("-- Sequence Node: ", name, " returning ", FAILURE, "!");
		return;
	}
	else if (child_nodes[current]->GetNodeState() == FAILURE)
	{
		++current;
		if (current >= child_nodes.size())
		{
			SetNodeState(SUCCESS);
			Utils::Log("-- Sequence Node: ", name, " returning ", SUCCESS, "!");
		}
	}
}

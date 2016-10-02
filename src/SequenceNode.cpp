#include "SequenceNode.h"
#include "Utils.h"

using namespace AeonBehaviorTree;

SequenceNode::SequenceNode(std::string name) : 
ControlNode(name)
{	
}

void SequenceNode::Execute(std::shared_ptr<BlackBoard> black_board)
{
	Utils::Log("-- SequenceNode : ", name, " Execute");
	if (child_nodes.size() == 0)
	{
		SetNodeState(SUCCESS);
		Utils::Log("-- Sequence Node: ", name, " returning ", SUCCESS, " (no childs to iterate)!");
		return;
	}	

	if (GetNodeState() != RUNNING)
	{
		SetNodeState(RUNNING);
		current = 0;
	}

	child_nodes[current]->Execute(black_board);

	
	if (child_nodes[current]->GetNodeState() == FAILURE)
	{
		SetNodeState(FAILURE);
		Utils::Log("-- Sequence Node: ", name, " returning ", FAILURE, "!");
		return;		
	}
	else if (child_nodes[current]->GetNodeState() == SUCCESS )
	{
		++current;
		if (current >= child_nodes.size())
		{			
			SetNodeState(SUCCESS);
			Utils::Log("-- Sequence Node: ", name, " returning ", SUCCESS, "!");
		}
	}
}

#include "SequenceNode.h"
#include "Utils.h"

using namespace AeonBehaviorTree;

SequenceNode::SequenceNode(std::string name) : 
ControlNode(name)
{	
}

SequenceNode::~SequenceNode() {}

void SequenceNode::Execute(BlackBoard * black_board)
{
	Utils::Log("-- SequenceNode : ", name, " Execute");
	if (child_nodes.size() == 0)
	{
		SetNodeState(SUCCESS);
		Utils::Log("-- Sequence Node: ", name, " returning ", SUCCESS, " (no childs to iterate)!");
		return;
	}	

	SetNodeState(RUNNING);

	if (child_nodes[current]->GetNodeState() == IDLE ||
		child_nodes[current]->GetNodeState() == RUNNING)
	{
		child_nodes[current]->Execute(black_board);
	}
	
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

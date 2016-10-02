#include "RepeaterNode.h"
#include "Utils.h"

using namespace AeonBehaviorTree;

RepeaterNode::RepeaterNode(std::string name) : 
DecoratorNode(name)
, num_repeats(0)
, current(0)
{
}

RepeaterNode::RepeaterNode(std::string name, int num_repeats) : 
  DecoratorNode(name)
, num_repeats(num_repeats)
, current(0)
{
}


void RepeaterNode::Execute(std::shared_ptr<BlackBoard> black_board)
{
	std::shared_ptr<TreeNode>  child_node = getChild();
	if (child_node == nullptr || num_repeats < 0)
	{
		SetNodeState(FAILURE);
		Utils::Log(" RepeaterNode Node: ", name, " returning ", FAILURE, "! because no child or num_repeats < 0)");
		return;
	}

	if (GetNodeState() != RUNNING)
	{
		SetNodeState(RUNNING);
		current = 0;
	}


	Utils::Log(" RepeaterNode Node: ", name, " repetition: " , current );
	
	child_node->Execute(black_board);

	if (child_node->GetNodeState() == FAILURE || child_node->GetNodeState() == SUCCESS)
	{
		++current;
	}
	
	if (current >= num_repeats)
	{		
		SetNodeState(child_node->GetNodeState());
		Utils::Log(" RepeaterNode Node: ", name, " returning ", state, "as the last rep. state");
	}
}
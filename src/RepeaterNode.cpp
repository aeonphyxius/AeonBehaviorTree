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

RepeaterNode::~RepeaterNode() 
{

}

void RepeaterNode::Execute(BlackBoard * black_board)
{
	TreeNode *childNode = getChild();
	if (childNode == nullptr || num_repeats < 0)
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
	
	childNode->Execute(black_board);

	if (childNode->GetNodeState() == FAILURE || childNode->GetNodeState() == SUCCESS)
	{
		++current;
	}
	
	if (current >= num_repeats)
	{		
		SetNodeState(childNode->GetNodeState());
		Utils::Log(" RepeaterNode Node: ", name, " returning ", state, "as the last rep. state");
	}
}
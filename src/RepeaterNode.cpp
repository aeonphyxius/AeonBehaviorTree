#include "RepeaterNode.h"
#include "Utils.h"

using namespace AeonBehaviorTree;

RepeaterNode::RepeaterNode(std::string name) : 
DecoratorNode(name)
, num_repeats(0)
{
}

RepeaterNode::RepeaterNode(std::string name, int num_repeats) : 
  DecoratorNode(name)
, num_repeats(num_repeats)
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

	Utils::Log(" RepeaterNode Node: ", name, " starting repetitions");
	for (unsigned short i = 0; i < num_repeats; ++i)
	{		
		childNode->Execute(black_board);
		++black_board->ticks;
	}

	SetNodeState(childNode->GetNodeState());		
	Utils::Log(" RepeaterNode Node: ", name, " returning ", state, "as the last rep. state");
}
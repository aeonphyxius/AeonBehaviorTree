#include "SequenceNode.h"
#include "Utils.h"

using namespace AeonBehaviorTree;

SequenceNode::SequenceNode(std::string name) : ControlNode(name)
{
}

SequenceNode::~SequenceNode() {}

void SequenceNode::Execute(BlackBoard * black_board)
{
	state = FAILURE;
	Utils::Log("-- SequenceNode : ", name , " Execute");
	for (auto child : childNodes)
	{
		child->Execute(black_board);
		if (child->GetNodeState() != SUCCESS)
		{
			return;
			Utils::Log("-- Sequence Node: ", name, " returning ", FAILURE, "!");
		}	
	}

	SetNodeState(SUCCESS);
	Utils::Log("-- Sequence Node: ", name, " returning ", SUCCESS, "!");
}

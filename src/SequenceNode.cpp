#include "SequenceNode.h"

using namespace AeonBehaviorTree;

SequenceNode::SequenceNode(std::string name) : ControlNode(name)
{
}

SequenceNode::~SequenceNode() {}

void SequenceNode::Execute()
{
	state = FAILURE;

	for (auto child : childNodes)
	{
		if (child->type == Action)
		{
			child->Execute();
			if (child->GetNodeState() != SUCCESS)
			{
				return;
				std::cout << " Sequence Node: " << name << " returning " << FAILURE << "!" << std::endl;
			}	
		}
	}

	SetNodeState(SUCCESS);
	std::cout << " Sequence Node: " << name << " returning " << SUCCESS << "!" << std::endl;
}

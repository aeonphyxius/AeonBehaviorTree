#include "SelectorNode.h"

using namespace AeonBehaviorTree;

SelectorNode::SelectorNode(std::string name) : ControlNode(name)
{
}

SelectorNode::~SelectorNode() {}

void SelectorNode::Execute(BlackBoard * black_board)
{
	state = FAILURE;

	for (auto child : childNodes)
	{
		if (child->type == Action)
		{
			child->Execute(black_board);
			if (child->GetNodeState() == SUCCESS)
			{
				SetNodeState(SUCCESS);
				std::cout << " SelectorNode Node: " << name << " returning " << SUCCESS << "!" << std::endl;
				return;
			}
				
		}
	}

	std::cout << " SelectorNode Node: " << name << " returning " << FAILURE << "!" << std::endl;
}

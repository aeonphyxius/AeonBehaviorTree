#include "RepeaterNode.h"

using namespace AeonBehaviorTree;

RepeaterNode::RepeaterNode(std::string name) : DecoratorNode(name)
{
}

RepeaterNode::~RepeaterNode() {}

void RepeaterNode::Execute()
{
	TreeNode *childNode = getChild();
	if (childNode == nullptr || num_repeats < 0)
	{
		SetNodeState(FAILURE);
		std::cout << " InverterNode Node: " << name << " returning " << FAILURE << "! because no child or num_repeats < 0)" << std::endl;
		return;
	}

	for (unsigned short i = 0; i < num_repeats; ++i)
	{
		childNode->Execute();
	}

	SetNodeState(childNode->GetNodeState());		
}
#include "InverterNode.h"

using namespace AeonBehaviorTree;

InverterNode::InverterNode(std::string name) : DecoratorNode(name)
{
}

InverterNode::~InverterNode() {}

void InverterNode::Execute()
{
	TreeNode *childNode = getChild();
	if (childNode == nullptr)
	{
		SetNodeState(FAILURE);
		std::cout << " InverterNode Node: " << name << " returning " << FAILURE << "! because no child" << std::endl;
		return;
	}

	childNode->Execute();
	SetNodeState(childNode->GetNodeState());

	if (childNode->GetNodeState() != SUCCESS)
		std::cout << " InverterNode Node: " << name << " returning " << FAILURE << "!" << std::endl;	
	else	
		std::cout << " InverterNode Node: " << name << " returning " << SUCCESS << "!" << std::endl;
	
}	
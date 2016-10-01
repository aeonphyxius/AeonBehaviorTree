#include "InverterNode.h"
#include "Utils.h"
using namespace AeonBehaviorTree;

InverterNode::InverterNode(std::string name) : DecoratorNode(name)
{
}

InverterNode::~InverterNode() {}

void InverterNode::Execute(BlackBoard * black_board)
{
	TreeNode *childNode = getChild();
	if (childNode == nullptr)
	{
		SetNodeState(FAILURE);
		Utils::Log( " InverterNode Node: ",name," returning ",FAILURE, "! because no child");
		return;
	}

	childNode->Execute(black_board);
	SetNodeState(childNode->GetNodeState());

	if (childNode->GetNodeState() != SUCCESS)
		Utils::Log(" InverterNode Node: ", name, " returning ", FAILURE, "!");
	else
		Utils::Log(" InverterNode Node: ", name, " returning ", SUCCESS, "!");
	
}	
#include "InverterNode.h"
#include "Utils.h"
using namespace AeonBehaviorTree;

InverterNode::InverterNode(std::string name) : DecoratorNode(name)
{
}

void InverterNode::Execute(std::shared_ptr<BlackBoard> black_board)
{
	std::shared_ptr<TreeNode> child_node = getChild();
	if (child_node == nullptr)
	{
		SetNodeState(FAILURE);
		Utils::Log( " InverterNode Node: ",name," returning ",FAILURE, "! because no child");
		return;
	}

	child_node->Execute(black_board);
	SetNodeState(child_node->GetNodeState());

	if (child_node->GetNodeState() != SUCCESS)
		Utils::Log(" InverterNode Node: ", name, " returning ", FAILURE, "!");
	else
		Utils::Log(" InverterNode Node: ", name, " returning ", SUCCESS, "!");
	
}	
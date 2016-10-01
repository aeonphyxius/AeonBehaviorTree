#include "ControlNode.h"
#include "Utils.h"
using namespace AeonBehaviorTree;

ControlNode::ControlNode(std::string name)
	: TreeNode(name)
	, current(0)
{
	state = IDLE;
}

ControlNode::~ControlNode() {}

void ControlNode::AddChild(TreeNode* child)
{

	if (Utils::ContainsChild(child_nodes, child))
	{		
		return;
	}		

	child_nodes.push_back(child);
}


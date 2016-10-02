#include "TreeNode.h"
#include "Utils.h"

using namespace AeonBehaviorTree;

TreeNode::TreeNode(std::string node_name)
{	
	name = node_name;
	state = IDLE;
}

TreeNode::~TreeNode() 
{
	child_nodes.clear();	
}

void TreeNode::AddChild(std::shared_ptr <TreeNode> child)
{

	if (Utils::ContainsChild(child_nodes, child))
	{
		return;
	}

	child_nodes.push_back(child);
}


#include "DecoratorNode.h"

using namespace AeonBehaviorTree;


DecoratorNode::DecoratorNode(std::string name) : TreeNode(name)
{
}

void DecoratorNode::AddChild(std::shared_ptr <TreeNode> child)
{
	// Only 1 child in decorator nodes
	if (child_nodes.empty())
	{
		child_nodes.push_back(child);
	}
		
	else
	{
		child_nodes.clear();
		child_nodes.push_back(child);
	}
}
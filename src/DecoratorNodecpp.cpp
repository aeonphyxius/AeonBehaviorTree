#include "DecoratorNode.h"

using namespace AeonBehaviorTree;


DecoratorNode::DecoratorNode(std::string name) : TreeNode(name)
{
	type = Control;
}

DecoratorNode::~DecoratorNode()
{
}


#include "ActionNode.h"

using namespace AeonBehaviorTree;

ActionNode::ActionNode(std::string name) : TreeNode(name)
{
	type = Action;
}

ActionNode::~ActionNode() 
{
}

#include "ConditionNode.h"

using namespace AeonBehaviorTree;

ConditionNode::ConditionNode(std::string name) : TreeNode(name)
{
	type = Condition;
}




#include "ConditionNode.h"

using namespace AeonBehaviorTree;

ConditionNode::ConditionNode(std::string name) : LeafNode(name)
{
	type = Condition;
}




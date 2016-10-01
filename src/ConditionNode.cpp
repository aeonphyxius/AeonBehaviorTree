#include "ConditionNode.h"

using namespace AeonBehaviorTree;

ConditionNode::ConditionNode(std::string name) : LeafNode(name)
{
	type = Condition;
}

ConditionNode::~ConditionNode() {}


void ConditionNode::WriteState(NodeState new_state)
{
	state = new_state;
}
/*
int ConditionNode::GetType()
{
	// Lock acquistion

	return CONDITION;
}

*/
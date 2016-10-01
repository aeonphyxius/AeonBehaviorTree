#include "ActionNode.h"

using namespace AeonBehaviorTree;

ActionNode::ActionNode(std::string name) : LeafNode(name)
{
	type = Action;
}

ActionNode::~ActionNode() 
{
}

void ActionNode::WriteState(NodeState new_state )
{
	state = new_state;
}
/*
int ActionNode::GetType() const
{
	return ACTION;
}
*/
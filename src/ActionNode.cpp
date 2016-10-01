#include "ActionNode.h"

using namespace AeonBehaviorTree;

ActionNode::ActionNode(std::string name) : LeafNode(name)
{
	type = Action;
}

ActionNode::~ActionNode() 
{
}

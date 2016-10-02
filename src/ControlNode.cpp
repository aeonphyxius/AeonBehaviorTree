#include "ControlNode.h"
#include "Utils.h"
using namespace AeonBehaviorTree;

ControlNode::ControlNode(std::string name)
	: TreeNode(name)
	, current(0)
{
	state = IDLE;
}


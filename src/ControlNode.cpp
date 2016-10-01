#include "ControlNode.h"
#include "Utils.h"
using namespace AeonBehaviorTree;

ControlNode::ControlNode(std::string name) : TreeNode(name)
{
	type = Control;
}

ControlNode::~ControlNode() {}

void ControlNode::AddChild(TreeNode* child)
{

	if (!Utils::ContainsChild(childNodes, child))
	{
		//throw BehaviorTreeException("'" + Child->Name + "' is already a '" + Name + "' child.");
	}
		

	childNodes.push_back(child);	
}

unsigned int ControlNode::GetChildrenNumber()
{
	return childNodes.size();
}


void ControlNode::WriteState(NodeState new_state)
{	
	state = new_state;
}

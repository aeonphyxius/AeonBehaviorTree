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
	//childStates.push_back(Idle);
}

unsigned int ControlNode::GetChildrenNumber()
{
	return childNodes.size();
}


void ControlNode::WriteState(NodeState new_state)
{	
	state = new_state;
}

/*
std::vector<TreeNode*> ControlNode::GetChildren()
{
	return ChildNodes;
}




int ControlNode::GetDepth()
{
	int depMax = 0;
	int dep = 0;
	for (int i = 0; i < ChildNodes.size(); i++)
	{
		dep = (ChildNodes[i]->GetDepth());
		if (dep > depMax)
		{
			depMax = dep;
		}

	}
	return 1 + depMax;
}

*/
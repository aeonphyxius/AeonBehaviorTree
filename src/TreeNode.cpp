#include "TreeNode.h"

using namespace AeonBehaviorTree;

TreeNode::TreeNode(std::string node_name)
{	
	name = node_name;
	state = IDLE;
}

TreeNode::~TreeNode() 
{
}

NodeState TreeNode::GetNodeState()
{	
	return state;
}

void TreeNode::SetNodeState(NodeState new_state)
{
	state = new_state;	
}

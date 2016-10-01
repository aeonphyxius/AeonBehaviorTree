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
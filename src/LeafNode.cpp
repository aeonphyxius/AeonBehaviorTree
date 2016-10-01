#include "LeafNode.h"

using namespace AeonBehaviorTree;

LeafNode::LeafNode(std::string name) : TreeNode(name) 
{
}

LeafNode::~LeafNode() 
{
}

int LeafNode::GetDepth()
{
	return 0;
}

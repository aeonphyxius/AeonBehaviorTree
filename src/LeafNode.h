#ifndef LEAFNODE_H
#define LEAFNODE_H

#include <vector>
#include "TreeNode.h"

namespace AeonBehaviorTree
{
	class LeafNode : public TreeNode
	{
	protected:
	public:
		LeafNode(std::string Name);
		~LeafNode();		
		int GetDepth();
	};
}

#endif

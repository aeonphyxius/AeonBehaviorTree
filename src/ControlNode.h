#ifndef CONTROLNODE_H
#define CONTROLNODE_H

#include <vector>

#include "TreeNode.h"

namespace AeonBehaviorTree
{
	class ControlNode : public TreeNode
	{
	public:		
		ControlNode(std::string name);
		~ControlNode();

		virtual void SetNodeState(NodeState new_state) { state = new_state; }
		void AddChild(TreeNode* child);
				
		
	protected:
		// Children vector
		std::vector<TreeNode*> child_nodes;

		unsigned int current;
				
		
	};
}

#endif

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
		~ControlNode() = default;

		virtual void SetNodeState(NodeState new_state) { state = new_state; }
		virtual NodeState GetNodeState() { return state; }
		void AddChild(TreeNode* child);

	protected:
		// Children vector
		std::vector<TreeNode*> child_nodes;

		unsigned int current;
				
		
	};
}

#endif

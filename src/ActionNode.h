#ifndef ACTION_NODE_H
#define ACTION_NODE_H

#include "TreeNode.h"

namespace AeonBehaviorTree
{
	class ActionNode : public TreeNode
	{
	public:
		
		ActionNode(std::string Name);
		~ActionNode();

		virtual void SetNodeState(NodeState new_state) { state = new_state; }
		virtual NodeState GetNodeState() { return state; }

		virtual void Execute(BlackBoard * black_board) = 0;
	};
}

#endif /*ACTION_NODE_H*/


#ifndef CONDITION_NODE_H
#define CONDITION_NODE_H

#include "TreeNode.h"

namespace AeonBehaviorTree
{
	class ConditionNode : public TreeNode
	{
	public:		
		ConditionNode(std::string name);
		~ConditionNode() = default;
				
		virtual void Execute(BlackBoard * black_board) = 0;				
		virtual void SetNodeState(NodeState new_state) { state = new_state; }
	};
}

#endif /* CONDITION_NODE_H */

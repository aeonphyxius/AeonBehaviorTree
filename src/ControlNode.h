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

		virtual void Execute(std::shared_ptr<BlackBoard> black_board) = 0;
		
		

	protected:
		

		unsigned int current;
				
		
	};
}

#endif

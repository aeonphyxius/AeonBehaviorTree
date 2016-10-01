#ifndef ACTIONNODE_H
#define ACTIONNODE_H

#include "LeafNode.h"

namespace AeonBehaviorTree
{
	class ActionNode : public LeafNode
	{
	public:
		// Constructor
		ActionNode(std::string Name);
		~ActionNode();

		virtual void SetNodeState(NodeState new_state) { state = new_state; }

		// The method that is going to be executed by the thread
		virtual void Execute(BlackBoard * black_board) = 0;
	};
}

#endif

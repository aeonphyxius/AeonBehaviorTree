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

		// The method that is going to be executed by the thread
		virtual void Execute() = 0;
				
		// Methods used to access the node state without the
		// conditional waiting (only mutual access)
		void WriteState(NodeState StateToBeSet);
		int GetType() const ;
	};
}

#endif

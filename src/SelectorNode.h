#ifndef SELECTORNODE_H
#define SELECTORNODE_H

#include "ControlNode.h"

namespace AeonBehaviorTree
{
	class SelectorNode : public ControlNode
	{
	public:
		// Constructor
		SelectorNode(std::string name);
		~SelectorNode();
		int GetType();
		// The method that is going to be executed by the thread
		void Execute();
	};
}

#endif
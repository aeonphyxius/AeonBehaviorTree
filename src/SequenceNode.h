#ifndef SEQUENCENODE_H
#define SEQUENCENODE_H

#include "ControlNode.h"

namespace AeonBehaviorTree
{
	class SequenceNode : public ControlNode
	{
	public:
		// Constructor
		SequenceNode(std::string Name);
		~SequenceNode();
		int GetType();
		
		void Execute();
	};
}

#endif /* SEQUENCENODE_H */

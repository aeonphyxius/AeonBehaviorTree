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
		virtual void SetNodeState(NodeState new_state) { state = new_state; }		
		
		void Execute(BlackBoard * black_board);
	};
}

#endif /* SEQUENCENODE_H */

#ifndef SEQUENCENODE_H
#define SEQUENCENODE_H

#include "ControlNode.h"

namespace AeonBehaviorTree
{
	class SequenceNode : public ControlNode
	{
	public:		
		SequenceNode(std::string Name);
		~SequenceNode() = default;
		
		void Execute(BlackBoard * black_board);
	};
}

#endif /* SEQUENCENODE_H */

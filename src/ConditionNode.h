
#ifndef CONDITION_NODE_H
#define CONDITION_NODE_H

#include "LeafNode.h"

namespace AeonBehaviorTree
{
	class ConditionNode : public LeafNode
	{
	public:		
		ConditionNode(std::string name);
		~ConditionNode() = default;
				
		virtual void Execute(BlackBoard * black_board) = 0;				
	};
}

#endif /* CONDITION_NODE_H */

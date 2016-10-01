
#ifndef CONDITIONNODE_H
#define CONDITIONNODE_H

#include "LeafNode.h"

namespace AeonBehaviorTree
{
	class ConditionNode : public LeafNode
	{
	public:
		// Constructor
		ConditionNode(std::string name);
		~ConditionNode();

		
		virtual void Execute(BlackBoard * black_board) = 0;
				
		void WriteState(NodeState new_state);
		//int GetType();
	};
}

#endif

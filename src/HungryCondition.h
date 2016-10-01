#ifndef HUNGRY_CONDITION_H
#define HUNGRY_CONDITION_H

#include "ConditionNode.h"

namespace AeonBehaviorTree
{
	class HungryCondition : public ConditionNode
	{
	public:
		// Constructor
		HungryCondition(std::string name);
		~HungryCondition() = default;
		
		// Execute implementation
		virtual void Execute(BlackBoard * black_board);
	};
}

#endif /*HUNGRY_CONDITION_H*/

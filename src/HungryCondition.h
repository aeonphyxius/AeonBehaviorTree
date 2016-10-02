#ifndef HUNGRY_CONDITION_H
#define HUNGRY_CONDITION_H

#include "ConditionNode.h"
#include <memory>

namespace AeonBehaviorTree
{
	class HungryCondition : public ConditionNode
	{
	public:
		// Constructor
		HungryCondition(std::string name);
		~HungryCondition() = default;
		
		// Execute implementation
		virtual void Execute(std::shared_ptr<BlackBoard> black_board);
	};
}

#endif /*HUNGRY_CONDITION_H*/

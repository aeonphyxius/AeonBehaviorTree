#ifndef BORED_CONDITION_H
#define BORED_CONDITION_H

#include "ConditionNode.h"
#include <memory>

namespace AeonBehaviorTree
{
	class BoredCondition : public ConditionNode
	{
	public:
		// Constructor
		BoredCondition(std::string name);
		~BoredCondition() = default;

		// Execute implementation
		virtual void Execute(std::shared_ptr<BlackBoard> black_board);
	};
}

#endif /*BORED_CONDITION_H*/

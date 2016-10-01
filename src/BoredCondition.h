#ifndef BORED_CONDITION_H
#define BORED_CONDITION_H

#include "ConditionNode.h"

namespace AeonBehaviorTree
{
	class BoredCondition : public ConditionNode
	{
	public:
		// Constructor
		BoredCondition(std::string name);
		~BoredCondition() = default;

		virtual void Execute(BlackBoard * black_board);
	};
}

#endif

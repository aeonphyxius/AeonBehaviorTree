#ifndef EAT_ACTION_H
#define EAT_ACTION_H

#include "ActionNode.h"

namespace AeonBehaviorTree
{
	class EatAction : public ActionNode
	{
	public:		
		// Constructor
		EatAction(std::string name);
		~EatAction() = default;
		
		// Execute implementation
		virtual void Execute(BlackBoard * black_board);
	};
}

#endif /*EAT_ACTION_H */

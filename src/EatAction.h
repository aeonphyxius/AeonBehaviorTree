#ifndef EAT_ACTION_H
#define EAT_ACTION_H

#include "ActionNode.h"

namespace AeonBehaviorTree
{
	class EatAction : public ActionNode
	{
	public:		
		EatAction(std::string name);
		~EatAction();

		virtual void Execute(BlackBoard * black_board);
	};
}

#endif /*EAT_ACTION_H */

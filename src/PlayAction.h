#ifndef PLAY_ACTION_H
#define PLAY_ACTION_H

#include "ActionNode.h"

namespace AeonBehaviorTree
{
	class PlayAction : public ActionNode
	{
	public:
		// Constructor
		PlayAction(std::string name);
		~PlayAction() = default;
				
		// Execute implementation
		virtual void Execute(std::shared_ptr<BlackBoard> black_board);
	};
}

#endif

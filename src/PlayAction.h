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
		~PlayAction();
				
		virtual void Execute(BlackBoard * black_board);		
	};
}

#endif

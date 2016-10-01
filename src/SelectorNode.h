#ifndef SELECTORNODE_H
#define SELECTORNODE_H

#include "ControlNode.h"

namespace AeonBehaviorTree
{
	class SelectorNode : public ControlNode
	{
	public:		
		SelectorNode(std::string name);
		~SelectorNode();	
		void Execute(BlackBoard * black_board);
	};
}

#endif

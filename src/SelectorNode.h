#ifndef SELECTOR_NODE_H
#define SELECTOR_NODE_H

#include "ControlNode.h"

namespace AeonBehaviorTree
{
	class SelectorNode : public ControlNode
	{
	public:		
		SelectorNode(std::string name);
		~SelectorNode() = default;
		void Execute(std::shared_ptr<BlackBoard> black_board);
	};
}

#endif /*SELECTOR_NODE_H*/

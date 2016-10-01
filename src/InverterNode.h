#ifndef INVERTER_NODE_H
#define INVERTER_NODE_H

#include "DecoratorNode.h"


namespace AeonBehaviorTree
{
	class InverterNode : public DecoratorNode
	{
	public:

		InverterNode(std::string name);
		~InverterNode();
		
		void Execute();
	};
}

#endif /* INVERTER_NODE_H */
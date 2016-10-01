#ifndef REPEATER_NODE_H
#define REPEATER_NODE_H

#include "DecoratorNode.h"


namespace AeonBehaviorTree
{
	class RepeaterNode : public DecoratorNode
	{
	public:

		RepeaterNode(std::string name);
		RepeaterNode(std::string name, int num_repeats);
		~RepeaterNode() = default;

		void Execute(BlackBoard * black_board);
		void SetNumRepeats(int repeats) { num_repeats = repeats; }

	private:
		unsigned int num_repeats;
		unsigned int current;
	};
} 
#endif /* REPEATER_NODE_H */
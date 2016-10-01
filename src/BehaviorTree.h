#ifndef BEHAVIORTREE_H
#define BEHAVIORTREE_H

#include "BlackBoard.h"
#include "ControlNode.h"
#include "Entity.h"


namespace AeonBehaviorTree
{
	class BehaviorTree
	{
	public:
		BehaviorTree();
		~BehaviorTree();
		void Execute(Entity *dog, BlackBoard * black_board);
		
		//void BehaviorTree::Execute(std::vector <Entity *> entites, std::vector <BlackBoard *> black_board, std::vector <ControlNode*> roots);
		void BehaviorTree::Execute(std::vector <Entity *> &entites, std::vector <BlackBoard *> &black_boards, std::vector <ControlNode*> &roots);

		void AddRootNode( ControlNode * new_root_node);

	private: 
		ControlNode * root;
	};
}


#endif /* BEHAVIORTREE_H */

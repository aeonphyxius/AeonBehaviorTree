#ifndef BEHAVIORTREE_H
#define BEHAVIORTREE_H

#include "BlackBoard.h"
#include "ControlNode.h"
#include "Entity.h"
#include <iostream>
#include <memory>

namespace AeonBehaviorTree
{
	class BehaviorTree
	{
	public:
		BehaviorTree();
		~BehaviorTree();

		typedef std::shared_ptr<BlackBoard> BlackBoardSharedPtr;
		typedef std::shared_ptr<Entity> EntitySharedPtr;

		void Execute(std::shared_ptr<Entity> entity, std::shared_ptr<BlackBoard> black_board);
		void Execute(std::vector <EntitySharedPtr> &entites, std::vector <BlackBoardSharedPtr> &black_boards, std::vector <ControlNode*> &roots);

		void AddRootNode(std::shared_ptr <ControlNode> new_root_node);
		
	private: 		
		std::shared_ptr<ControlNode> root;
	};
}


#endif /* BEHAVIORTREE_H */

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <string>
#include "BlackBoard.h"
#include <vector>

namespace AeonBehaviorTree
{	
	
	// Enumerates the states every node can be in after execution during a particular
	// time step:
	// - "IDLE" Indicates that the node still did not start executing its task;
	// - "SUCCESS" indicates that the node has completed running during this time step;
	// - "FAILURE" indicates that the node has determined it will not be able to complete its task;
	// - "RUNNING" indicates that the node has successfully moved forward during this
	//   time step, but the task is not yet complete;	
	enum NodeState { IDLE,SUCCESS, FAILURE, RUNNING};

	// Abstract base class for Behavior Tree Nodes
	class TreeNode
	{	
	public:		
		std::string name;						
				
		TreeNode(std::string node_name);
		~TreeNode();
		
		virtual void AddChild(std::shared_ptr <TreeNode> child);
		virtual void Execute(std::shared_ptr<BlackBoard> black_board) = 0;
		virtual void SetNodeState(NodeState new_state) = 0;
		virtual NodeState GetNodeState() = 0;
		

	protected:
		NodeState state;		
		std::vector<std::shared_ptr <TreeNode>> child_nodes;
	};
}

#endif

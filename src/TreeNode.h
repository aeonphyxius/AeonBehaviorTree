#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <string>

namespace AeonBehaviorTree
{	
	enum NodeType { Action, Condition, Control };
	//enum ColorNodeType { PARALLEL, SELECTOR, SEQUENCE, SEQUENCESTAR, SELECTORSTAR, ACTION, CONDITION, DECORATOR };
	// Enumerates the states every node can be in after execution during a particular
	// time step:
	// - "Success" indicates that the node has completed running during this time step;
	// - "Failure" indicates that the node has determined it will not be able to complete
	//   its task;
	// - "Running" indicates that the node has successfully moved forward during this
	//   time step, but the task is not yet complete;	
	enum NodeState { IDLE,SUCCESS, FAILURE, RUNNING};

	// Abstract base class for Behavior Tree Nodes
	class TreeNode
	{
	protected:		
		NodeState state;
		NodeState ColorState;
	public:
		// Node name
		std::string name;

		// Node type
		NodeType type;

		// The constructor and the distructor
		TreeNode(std::string Name);
		~TreeNode();

		// The method that retrive the state of the node
		// (conditional waiting and mutual access)
		NodeState GetNodeState();
		void SetNodeState(NodeState new_state);
		
		
		// The method that is going to be executed by the thread
		virtual void Execute() = 0;
		//virtual int GetType() = 0;
		virtual void WriteState(NodeState new_state) = 0;		
		virtual int GetDepth() = 0;

	};
}

#endif

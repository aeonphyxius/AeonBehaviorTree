#ifndef CONTROLNODE_H
#define CONTROLNODE_H

#include <vector>

#include "TreeNode.h"

namespace AeonBehaviorTree
{
	class ControlNode : public TreeNode
	{
	public:
		// Constructor
		ControlNode(std::string name);
		~ControlNode();

		// The method used to fill the child vector
		void AddChild(TreeNode* child);

		// The method used to know the number of children
		unsigned int GetChildrenNumber();
		void WriteState(NodeState StateToBeSet);

		//std::vector<TreeNode*> GetChildren();
		// The method used to interrupt the execution of the node
		//bool Halt();
		//void ResetColorState();
		//void HaltChildren(int i);
		//int GetDepth();

		// Methods used to access the node state without the
		// conditional waiting (only mutual access)
		
	protected:
		// Children vector
		std::vector<TreeNode*> childNodes;

		// Children states
		std::vector<NodeState> childStates;

		// Vector size
		unsigned int M;

	};
}

#endif

#ifndef DECORATOR_NODE_H
#define DECORATOR_NODE_H

#include "ControlNode.h"
#include "TreeNode.h"

namespace AeonBehaviorTree
{
	class DecoratorNode : public TreeNode
	{
	public:
	
		DecoratorNode(std::string name);
		~DecoratorNode() = default;
		void setChild(TreeNode * newChild) { child = newChild; }
		virtual void SetNodeState(NodeState new_state) { state = new_state; }
		virtual NodeState GetNodeState() { return state; }
	
	protected:
		TreeNode* getChild() const { return child; }

	private:
		TreeNode* child;
	};
}
#endif /* DECORATOR_NODE_H */
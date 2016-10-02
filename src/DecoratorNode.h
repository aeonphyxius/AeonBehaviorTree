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
				
		virtual void AddChild(std::shared_ptr <TreeNode> child);
		virtual void SetNodeState(NodeState new_state) { state = new_state; }
		virtual NodeState GetNodeState() { return state; }
		virtual void Execute(std::shared_ptr<BlackBoard> black_board) = 0;
	
	protected:
		std::shared_ptr <TreeNode> getChild() const { return child_nodes[0]; }
			
		
	};
}
#endif /* DECORATOR_NODE_H */
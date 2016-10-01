#include "BehaviorTree.h"

using namespace AeonBehaviorTree;


void Execute(ControlNode* root, int TickPeriod_milliseconds)
{
	std::cout << "Start Drawing!" << std::endl;
	while (true)
	{
		std::cout << "Ticking the root node !" << std::endl << std::endl;

		// Printing its state
		root->GetNodeState();

		/*if (root->ReadState() != Running)
		{
			//when the root returns a status it resets the colors of the tree
			root->ResetColorState();
		}*/		
	}

}

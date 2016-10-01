#include <iostream>
#include "BehaviorTree.h"
#include "SequenceNode.h"
#include "Utils.h"
#include "Dog.h"
#include "Entity.h"
#include "BlackBoard.h"
#include "RepeaterNode.h"
#include "EatAction.h"
#include "PlayAction.h"

using namespace std;
using namespace AeonBehaviorTree;

int main()
{
	BehaviorTree * myDogBehavior = new BehaviorTree();
	BlackBoard * myBlackBoard = new BlackBoard();
	Entity *dog1 = new Dog();

	SequenceNode * root = new SequenceNode("root_sel_node");		

	RepeaterNode *rep_eating_node = new RepeaterNode("rep_eating_node", 5);
	EatAction *eat_node = new EatAction("eat_action");
	rep_eating_node->setChild(eat_node);

	RepeaterNode *rep_node_play = new RepeaterNode("rep_node_play", 5);
	PlayAction *play_node = new PlayAction("PlayAction");
	rep_node_play->setChild(play_node);
	
	root->AddChild(rep_eating_node);
	root->AddChild(rep_node_play);

	//root->AddChild();

	myDogBehavior->AddRootNode(root);
	myDogBehavior->Execute(dog1, myBlackBoard);


	std::cout << std::endl << std::endl << std::endl;
	Utils::Log(" Dog1 final status -> ENERGY: ", dog1->energy, "  LAST_PLAYED_TIME: ", dog1->last_played_time);
	system("pause");

	return 0;
}
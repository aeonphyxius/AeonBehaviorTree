
#include <iostream>
#include "BehaviorTree.h"
#include "SequenceNode.h"
#include "Dog.h"
#include "Entity.h"
#include "BlackBoard.h"
#include "RepeaterNode.h"
#include "EatAction.h"
#include "PlayAction.h"
#include "SelectorNode.h"
#include "HungryCondition.h"

using namespace std;
using namespace AeonBehaviorTree;

int main()
{
	BehaviorTree * myDogBehavior = new BehaviorTree();
	BlackBoard * myBlackBoard = new BlackBoard();
	
	Entity *dog1 = new Dog();
	Entity *dog2 = new Dog();
	Entity *dog3 = new Dog();

	SequenceNode * root = new SequenceNode("root_sel_node");		

	SelectorNode * sel_node = new SelectorNode("sel_node");
	HungryCondition * hun_con1 = new HungryCondition("hun_con1");
	HungryCondition * hun_con2 = new HungryCondition("hun_con2");

	sel_node->AddChild(hun_con1);
	sel_node->AddChild(hun_con2);
	

	RepeaterNode *rep_eating_node = new RepeaterNode("rep_eating_node", 5);
	EatAction *eat_node = new EatAction("eat_action");
	rep_eating_node->setChild(eat_node);

	RepeaterNode *rep_node_play = new RepeaterNode("rep_node_play", 3);
	PlayAction *play_node = new PlayAction("PlayAction");
	rep_node_play->setChild(play_node);
	
	root->AddChild(sel_node);
	root->AddChild(rep_eating_node);
	root->AddChild(rep_node_play);
	
	myDogBehavior->AddRootNode(root);
	myDogBehavior->Execute(dog1, myBlackBoard);
	myDogBehavior->Execute(dog2, myBlackBoard);
	myDogBehavior->Execute(dog3, myBlackBoard);


	std::cout << std::endl << std::endl << std::endl;
	dog1->DebugValues();
	dog2->DebugValues();
	dog3->DebugValues();
	system("pause");

	return 0;
}

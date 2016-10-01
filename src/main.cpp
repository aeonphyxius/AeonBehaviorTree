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
#include "InverterNode.h"
#include "BoredCondition.h"

using namespace std;
using namespace AeonBehaviorTree;

namespace TestInverter
{
	int ExecuteTest()
	{
		BehaviorTree * myDogBehavior = new BehaviorTree();
		BlackBoard * myBlackBoard = new BlackBoard();

		Entity *dog1 = new Dog();
		
		SequenceNode * root = new SequenceNode("root_sel_node");


		RepeaterNode *rep_node_play = new RepeaterNode("rep_node_play", 5);
		PlayAction *play_node = new PlayAction("PlayAction");
		rep_node_play->setChild(play_node);
		

		SequenceNode * sequence = new SequenceNode("sequence_node");
		BoredCondition * bored = new BoredCondition("bored_condition");
		InverterNode * inverter = new InverterNode("inverter_node");
		inverter->setChild(bored);

		RepeaterNode *rep_eating_node = new RepeaterNode("rep_eating_node", 3);
		EatAction *eat_node = new EatAction("eat_action");
		rep_eating_node->setChild(eat_node);

		sequence->AddChild(inverter);
		sequence->AddChild(rep_eating_node);

		
		root->AddChild(rep_node_play);
		root->AddChild(sequence);

		myDogBehavior->AddRootNode(root);
		myDogBehavior->Execute(dog1, myBlackBoard);
		

		std::cout << std::endl << std::endl << std::endl;
		dog1->DebugValues();		
		system("pause");

		return 0;
	}

}


namespace TestConcurrentDiffValues
{	
	void ExecuteTestConcurrentDiffValues()
	{
		const int DOGS_NUMBER = 5;
		BehaviorTree * myDogBehavior = new BehaviorTree();

		std::vector<BlackBoard *> myBlackBoards = std::vector<BlackBoard*>();
		std::vector<ControlNode *> roots = std::vector<ControlNode*>();
		std::vector<Entity*> dogs = std::vector<Entity*>();

		for (unsigned int i = 0; i < DOGS_NUMBER; ++i)
		{
			dogs.push_back(new Dog(0.2f * i));
			myBlackBoards.push_back(new BlackBoard());
			roots.push_back(new SequenceNode("root_sel_node" + i));
		}

		for (unsigned int i = 0; i < DOGS_NUMBER; ++i)
		{
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

			roots[i]->AddChild(sel_node);
			roots[i]->AddChild(rep_eating_node);
			roots[i]->AddChild(rep_node_play);
			//myDogBehaviors[i]->AddRootNode(roots[i]);
		}

		myDogBehavior->Execute(dogs, myBlackBoards, roots);

		std::cout << std::endl << std::endl << std::endl;

		for (auto dog : dogs)
			dog->DebugValues();


		system("pause");
	}

}

namespace TestConcurrentDogs
{	
	void ExecuteTestConcurrentDogs()
	{
		const int DOGS_NUMBER = 5;
		//std::vector< BehaviorTree *> myDogBehavior = std::vector<BehaviorTree*>();
		BehaviorTree * myDogBehavior = new BehaviorTree();

		std::vector<BlackBoard *> myBlackBoards = std::vector<BlackBoard*>();
		std::vector<ControlNode *> roots = std::vector<ControlNode*>();
		std::vector<Entity*> dogs = std::vector<Entity*>();

		for (unsigned int i = 0; i < DOGS_NUMBER; ++i)
		{
			dogs.push_back(new Dog());
			//myDogBehaviors.push_back(new BehaviorTree());
			myBlackBoards.push_back(new BlackBoard());
			roots.push_back(new SequenceNode("root_sel_node" + i));
		}

		for (unsigned int i = 0; i < DOGS_NUMBER; ++i)
		{
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

			roots[i]->AddChild(sel_node);
			roots[i]->AddChild(rep_eating_node);
			roots[i]->AddChild(rep_node_play);
		}

		myDogBehavior->Execute(dogs, myBlackBoards, roots);

		std::cout << std::endl << std::endl << std::endl;

		for (auto dog : dogs)
			dog->DebugValues();


		system("pause");
	}
}

namespace Test3ParallelDogs
{
	int ExecuteTest()
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

}

int main()
{
	TestInverter::ExecuteTest();

	//Test3ParallelDogs::ExecuteTest();

	//TestConcurrentDiffValues::ExecuteTestConcurrentDiffValues();

	//TestConcurrentDogs::ExecuteTestConcurrentDogs();
}

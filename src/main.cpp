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
		unique_ptr <BehaviorTree> myDogBehavior (new BehaviorTree());
		shared_ptr <BlackBoard> myBlackBoard = make_shared <BlackBoard>();
		shared_ptr<Entity> dog1 = make_shared<Dog>();
		
		shared_ptr<SequenceNode> root = make_shared<SequenceNode>("root_sel_node");


		std::shared_ptr<RepeaterNode> rep_node_play ( new RepeaterNode("rep_node_play", 5));
		std::shared_ptr<PlayAction> play_node(new PlayAction("PlayAction"));
		rep_node_play->AddChild(play_node);
		

		std::shared_ptr<SequenceNode> sequence (new SequenceNode("sequence_node"));
		std::shared_ptr<BoredCondition> bored(new BoredCondition("bored_condition"));
		std::shared_ptr<InverterNode>inverter(new InverterNode("inverter_node"));
		inverter->AddChild(bored);

		std::shared_ptr<RepeaterNode>rep_eating_node (new RepeaterNode("rep_eating_node", 3));
		std::shared_ptr<EatAction> eat_node (new EatAction("eat_action"));
		rep_eating_node->AddChild(eat_node);

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
		unique_ptr <BehaviorTree> myDogBehavior(new BehaviorTree());

		std::vector<BehaviorTree::BlackBoardSharedPtr> myBlackBoards = std::vector<BehaviorTree::BlackBoardSharedPtr>();
		std::vector<ControlNode *> roots = std::vector<ControlNode*>();
		std::vector<BehaviorTree::EntitySharedPtr> dogs = std::vector<BehaviorTree::EntitySharedPtr>();

		for (unsigned int i = 0; i < DOGS_NUMBER; ++i)
		{
			dogs.push_back(make_shared <Dog>(0.2f * i));
			myBlackBoards.push_back(unique_ptr<BlackBoard>(new BlackBoard()));
			roots.push_back(new SequenceNode("root_sel_node" + i));
		}

		for (unsigned int i = 0; i < DOGS_NUMBER; ++i)
		{
			std::shared_ptr<SelectorNode>sel_node (new SelectorNode("sel_node"));
			std::shared_ptr<HungryCondition> hun_con1 (new HungryCondition("hun_con1"));
			std::shared_ptr<HungryCondition> hun_con2(new HungryCondition("hun_con2"));
			
			sel_node->AddChild(hun_con1);
			sel_node->AddChild(hun_con2);


			std::shared_ptr<RepeaterNode> rep_eating_node ( new RepeaterNode("rep_eating_node", 5));
			std::shared_ptr<EatAction > eat_node ( new EatAction("eat_action"));
			rep_eating_node->AddChild(eat_node);

			std::shared_ptr<RepeaterNode >rep_node_play (new RepeaterNode("rep_node_play", 3));
			std::shared_ptr<PlayAction> play_node(new PlayAction("PlayAction"));
			rep_node_play->AddChild(play_node);

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

namespace TestConcurrentDogs
{	
	void ExecuteTestConcurrentDogs()
	{
		const int DOGS_NUMBER = 5;		
		unique_ptr <BehaviorTree> myDogBehavior(new BehaviorTree());

		std::vector<BehaviorTree::BlackBoardSharedPtr> myBlackBoards = std::vector<BehaviorTree::BlackBoardSharedPtr>();
		std::vector<ControlNode *> roots = std::vector<ControlNode*>();
		std::vector<BehaviorTree::EntitySharedPtr> dogs = std::vector<BehaviorTree::EntitySharedPtr>();

		for (unsigned int i = 0; i < DOGS_NUMBER; ++i)
		{
			dogs.push_back(make_shared <Dog>());
			//myDogBehaviors.push_back(new BehaviorTree());
			myBlackBoards.push_back(unique_ptr<BlackBoard>(new BlackBoard()));
			roots.push_back(new SequenceNode("root_sel_node" + i));
		}

		for (unsigned int i = 0; i < DOGS_NUMBER; ++i)
		{
			std::shared_ptr<SelectorNode>sel_node(new SelectorNode("sel_node"));
			std::shared_ptr<HungryCondition> hun_con1(new HungryCondition("hun_con1"));
			std::shared_ptr<HungryCondition> hun_con2(new HungryCondition("hun_con2"));

			sel_node->AddChild(hun_con1);
			sel_node->AddChild(hun_con2);


			std::shared_ptr<RepeaterNode> rep_eating_node ( new RepeaterNode("rep_eating_node", 5));
			std::shared_ptr<EatAction> eat_node ( new EatAction("eat_action"));
			rep_eating_node->AddChild(eat_node);

			std::shared_ptr<RepeaterNode>rep_node_play (new RepeaterNode("rep_node_play", 3));
			std::shared_ptr<PlayAction> play_node(new PlayAction("PlayAction"));
			rep_node_play->AddChild(play_node);

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
		shared_ptr <BlackBoard> myBlackBoard = make_shared <BlackBoard>();
		unique_ptr <BehaviorTree> myDogBehavior(new BehaviorTree());

		shared_ptr<Entity> dog1 = make_shared<Dog>();
		shared_ptr<Entity> dog2 = make_shared<Dog>();
		shared_ptr<Entity> dog3 = make_shared<Dog>();

		shared_ptr<SequenceNode> root = make_shared<SequenceNode>("root_sel_node");

		std::shared_ptr<SelectorNode>sel_node(new SelectorNode("sel_node"));
		std::shared_ptr<HungryCondition> hun_con1(new HungryCondition("hun_con1"));
		std::shared_ptr<HungryCondition> hun_con2(new HungryCondition("hun_con2"));

		sel_node->AddChild(hun_con1);
		sel_node->AddChild(hun_con2);


		std::shared_ptr<RepeaterNode> rep_eating_node (new RepeaterNode("rep_eating_node", 5));
		std::shared_ptr<EatAction>eat_node (new EatAction("eat_action"));
		rep_eating_node->AddChild(eat_node);

		std::shared_ptr<RepeaterNode> rep_node_play (new RepeaterNode("rep_node_play", 3));
		std::shared_ptr<PlayAction> play_node (new PlayAction("PlayAction"));
		rep_node_play->AddChild(play_node);

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

	TestConcurrentDiffValues::ExecuteTestConcurrentDiffValues();		
	
	TestConcurrentDogs::ExecuteTestConcurrentDogs();
	
	Test3ParallelDogs::ExecuteTest();
}

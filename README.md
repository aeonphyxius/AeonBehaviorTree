To develop my Behavior tree I have used this Gamasutra article as a reference:
http://www.gamasutra.com/blogs/ChrisSimpson/20140717/221339/Behavior_trees_for_AI_How_they_work.php
together with this book:
https://books.google.nl/books?id=OMb1CwAAQBAJ

In order to get some knowledget on the subject

I also tried to follow as much as possible the Google coding style
https://google.github.io/styleguide/cppguide.html#Local_Variables


The following is the class strtucture I have used to develop this BT:

********************************************************************************************************************************************************************
															---------------
															| TreeNode 	  |
															---------------
								-----------------------------------|-----------------------------------------------------
								|		 		|			 				|											|
					--------------  	----------------- 				--------------  						-----------------
					| ControlNode |		| DecoratorNode |				| ActionNode |							| ConditionNode |
					--------------		-----------------				--------------							-----------------
		-----------------|						|----------------					|------------------					|--------------------------
		|				 |  					|				|					|				  |					|						   |
---------------  	---------------- 	---------------  	---------------- 	---------------  	------------- 	-----------------  	-----------------
| SelectorNode 		| SequenceNode |	| InverterNode|		| RepeaterNode |	| PlayAction  |		| EatAction |	| HungryCondition|	| BoredCondition|
---------------		----------------	---------------		----------------	---------------		-------------	-----------------	-----------------


As you can see I have split in 4 types the TreeNodes ( Control, Decorator, Action and Condition). While Selector, Sequence Invert and Repeat, are generic nodes, PlayAction
Eat, Hungry and Bored are specific nodes for this Dog exercise

#Run the test
To run the test, just comment and uncomment the method calls in the main.cpp 
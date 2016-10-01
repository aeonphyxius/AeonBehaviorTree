#ifndef BEHAVIORTREE_H
#define BEHAVIORTREE_H

#include "SelectorNode.h"
#include "SequenceNode.h"

//#include <Exceptions.h>

#include <string>
#include <map>

#include <typeinfo>
#include <math.h>       /* pow */


void Execute(AeonBehaviorTree::ControlNode* root, int TickPeriod_milliseconds);


#endif

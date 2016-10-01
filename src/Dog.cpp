#include "Dog.h"

using namespace AeonBehaviorTree;

Dog::Dog() : Entity()
{
	energy = 1.0f;
	last_played_time = 0.0f;
}

bool Dog::IsHungry() const 
{ 
	return energy <= THRESHOLD; 
}

void Dog::Eat(const float time)
{ 
	energy += EAT_VALUE; 
	energy = energy > MAX_ENERGY ? MAX_ENERGY : energy;
}

void Dog::Play(const float time) 
{ 
	energy -= PLAY_ENERGY; 	

	last_played_time = time;
}

bool Dog::Bored(const float time) const
{ 
	return time - last_played_time > BORED_THRESHOLD; 
}
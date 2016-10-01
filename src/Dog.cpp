#include "Dog.h"
#include "Utils.h"


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

void Dog::Eat()
{ 
	energy += EAT_VALUE; 
	energy = energy > MAX_ENERGY ? MAX_ENERGY : energy;
}

void Dog::Play(const float time) 
{ 
	energy -= PLAY_ENERGY; 	
	energy = energy < 0.0f ? 0.0f : energy;

	last_played_time = time;
}

bool Dog::IsBored(const float time) const
{ 
	return time - last_played_time > BORED_THRESHOLD; 
}

void Dog::DebugValues() const
{
	Utils::Log (" Dog1 final status -> ENERGY: ", energy, "  LAST_PLAYED_TIME: ", last_played_time);
}
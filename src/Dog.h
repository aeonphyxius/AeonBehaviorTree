#ifndef DOG_H
#define DOG_H

#include "Entity.h"

namespace AeonBehaviorTree
{
	class Dog : public Entity
	{
	public: 
		Dog();
		~Dog() = default;

		virtual bool IsHungry() const;
		virtual void Eat();
		virtual void Play(const float time);
		virtual bool Bored(const float time) const;
		virtual void DebugValues()const;

	private:
		const float THRESHOLD = 0.5f;
		const float EAT_VALUE = 0.1f;
		const float PLAY_ENERGY = 0.2f;
		const float BORED_THRESHOLD = 0.5f;
		const float MAX_ENERGY = 1.2f;
		
		float energy;
		float last_played_time;

	};
}

#endif /* DOG_H */

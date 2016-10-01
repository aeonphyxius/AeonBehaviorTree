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
		virtual void Eat(const float time);
		virtual void Play(const float time);
		virtual bool Bored(const float time) const;
				

	private:
		const float THRESHOLD = 0.5f;
		const float EAT_VALUE = 0.1f;
		const float PLAY_ENERGY = 0.1f;
		const float BORED_THRESHOLD = 0.5f;
		const float MAX_ENERGY = 0.5f;


	};
}

#endif /* DOG_H */

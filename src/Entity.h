#ifndef ENTITY_H
#define ENTITY_H


namespace AeonBehaviorTree
{
	class Entity 
	{
	public:

		Entity() = default;
		~Entity() = default;
	
		virtual bool IsHungry() const  = 0;
		virtual void Eat(const float time) = 0;
		virtual void Play(const float time) = 0;
		virtual bool Bored(const float time) const = 0;	

		float energy;
		float last_played_time;
	};
}

#endif /* ENTITY_H */

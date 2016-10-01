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
		virtual void Eat() = 0;
		virtual void Play(const float time) = 0;
		virtual bool IsBored(const float time) const = 0;
		virtual void DebugValues() const = 0;

	};
}

#endif /* ENTITY_H */

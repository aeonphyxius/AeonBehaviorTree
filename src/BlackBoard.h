#ifndef BLACK_BOARD_H
#define BLACK_BOARD_H

#include "Entity.h"
#include <memory>
namespace AeonBehaviorTree
{
	class BlackBoard
	{
	public:
		BlackBoard() = default;
		~BlackBoard() = default;

		float ticks;
		std::shared_ptr<Entity> entity;

	private:
		BlackBoard(BlackBoard const&) = default;
		void operator=(BlackBoard const&){};
	};
}
#endif /* BLACK_BOARD_H */
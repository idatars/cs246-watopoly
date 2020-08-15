#include "nonproperty.h"
#include "player.h"
#include "board.h"

class NH : public NonProperty {
	Board* board;
public:
	NH(Board& b);
	void playerEffect(std::shared_ptr<Player>) override;
};

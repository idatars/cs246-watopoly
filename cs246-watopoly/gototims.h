#include "nonproperty.h"
#include "player.h"

class GoToTims : public NonProperty {
public:
	GoToTims();
	void playerEffect(Player&);
};

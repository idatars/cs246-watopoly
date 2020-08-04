#include "nonproperty.h"
#include "player.h"

class NH : public NonProperty {
public:
	NH();
	void playerEffect(Player&) override;
};

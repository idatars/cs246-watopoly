
#include "nonproperty.h"

class OSAP : public NonProperty {
public:
	OSAP();
	void playerEffect(Player&) override;
};

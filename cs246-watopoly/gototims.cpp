#include "gototims.h"

GoToTims::GoToTims() : NonProperty("Go To Tims")
{
}

void GoToTims::playerEffect(std::shared_ptr<Player> p) {
	p->setPos(10);
	p->setInTims(true);
}

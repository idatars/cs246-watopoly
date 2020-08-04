#include "gototims.h"

GoToTims::GoToTims() : NonProperty("Go To Tims")
{
}

void GoToTims::playerEffect(Player& p) {
	p.setPos(10);
	p.setInTims(true);
}

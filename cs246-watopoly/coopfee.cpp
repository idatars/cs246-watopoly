#include "coopfee.h"

CoopFee::CoopFee() : NonProperty("Co-op Fee")
{
}

void CoopFee::playerEffect(Player& p)
{
	p.withdrawMoney(150);
}

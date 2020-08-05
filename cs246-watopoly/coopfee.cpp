#include "coopfee.h"

CoopFee::CoopFee() : NonProperty("Co-op Fee")
{
}

void CoopFee::playerEffect(std::shared_ptr<Player>)
{
	p.withdrawMoney(150);
}

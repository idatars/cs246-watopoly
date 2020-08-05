#ifndef _GYM_
#define _GYM_

#include "property.h"
#include <random>

class Gym : public Property {
public:
	Gym(std::string name);
	int usageFees();
	void playerEffect(std::shared_ptr<Player>);
	void mortgageBy(Player * player) override;
	void unmortgageBy(Player * player) override;
};

#endif


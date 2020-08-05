#ifndef _GYM_
#define _GYM_

#include "property.h"
#include <random>

class Gym : public Property {
public:
	Gym(std::string name);
	int usageFees();
	void playerEffect(Player&);
	void mortage(Player * player) override;
	void unmortage(Player * player) override;
};

#endif


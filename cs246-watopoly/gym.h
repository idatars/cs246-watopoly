#ifndef _GYM_
#define _GYM_

#include "property.h"
#include <random>

class Gym : public Property {
public:
	Gym(std::string name);
	int usageFees();
	void playerEffect(Player&);
	int getImprovements() override;
	void setImprovements(int improvement) override;
};

#endif


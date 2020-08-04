#ifndef _RESIDENCE_
#define _RESIDENCE_

#include "property.h"
#include <vector>
#include <string>

class Residence : public Property {
	int rent[4] = { 25, 50, 100, 200 };
public:
	Residence(std::string name);
	int getRent();
	void playerEffect(Player&);
};

#endif


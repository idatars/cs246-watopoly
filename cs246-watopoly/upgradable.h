#ifndef _UPGRADABLE_
#define _UPGRADABLE_

#include "property.h"
#include <memory>
#include <vector>
#include "monopolyblock.h"

class Upgradable : public Property {
	int improvementCost;
	int tuition[6];
	int improvements = 0;
	std::shared_ptr<Player> owner = nullptr;
	std::shared_ptr<MonopolyBlock> block;
public:
	Upgradable(std::string name, int c, int ic, int t0, int t1, int t2, int t3, int t4, int t5, std::shared_ptr<MonopolyBlock> b);
	int getImprovementCost();
	int getImprovements();
	int getTuition();
	void playerEffect(Player&);
};

#endif


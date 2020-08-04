#ifndef _MONOPOLYBLOCK_
#define _MONOPOLYBLOCK_


#include <vector>
#include <memory>

class Upgradable;

class MonopolyBlock {
	std::vector<Upgradable*> members;
public:
	MonopolyBlock() {}
	std::vector<Upgradable*> getMembers();
};

#endif


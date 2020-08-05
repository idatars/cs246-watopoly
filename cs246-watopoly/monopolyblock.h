#ifndef _MONOPOLYBLOCK_
#define _MONOPOLYBLOCK_


#include <vector>
#include <memory>

class Property;

class MonopolyBlock {
	std::vector<Property*> members;
public:
	MonopolyBlock() {}
	std::vector<Property*> getMembers();
};

#endif


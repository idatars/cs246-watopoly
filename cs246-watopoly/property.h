#ifndef _PROPERTY_
#define _PROPERTY_

#include <memory>
#include "player.h"
#include "square.h"

class Player;
class Square;

class Property : public Square {
	int cost;
	Player * owner = nullptr;
	int mortgage;
	std::vector<Property*> monopolyBlock;
public:
	Property(std::string& name, int c);
	int getCost();
	Player* getOwner();
	void setOwner(Player&);
	int getMortgage();
	virtual void playerEffect(Player&) = 0;
};

class Auction {
public:
	Property* p;
	Auction(Property& prop) : p{ &prop } {}
};

#endif


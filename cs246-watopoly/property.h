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
	bool mortgaged= false;
	int mortgage;
	std::vector<Property*> monopolyBlock;
public:
	Property(std::string& name, int c);
	int getCost();
	Player* getOwner();
	void setOwner(Player&);
	int getMortgage();
	virtual void playerEffect(Player&) = 0;
	bool isMortgaged();
	void setMortgaged();
	void setUnmortgaged();
	virtual void mortgageBy(Player * player) = 0; // property mortaged by player
	virtual void unmortgageBy(Player * player) = 0; // property unmortaged by plater
};

class Auction {
public:
	Property* p;
	Auction(Property& prop) : p{ &prop } {}
};

#endif


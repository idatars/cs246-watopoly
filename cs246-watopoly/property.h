#ifndef _PROPERTY_
#define _PROPERTY_

#include <memory>
#include "player.h"
#include "square.h"
#include "monopolyblock.h"

class Player;
class Square;

class Property : public Square {
	int cost;
	Player * owner = nullptr;
	bool mortgaged= false;
	int mortgage;
	std::shared_ptr<MonopolyBlock> block;
public:
	Property(std::string& name, int c, std::shared_ptr<MonopolyBlock> b);
	int getCost();
	Player* getOwner();
	void setOwner(Player&);
	int getMortgage();
<<<<<<< HEAD
	virtual void playerEffect(Player&) = 0;
	virtual int getImprovements() = 0;
	virtual void setImprovements(int improvement) = 0;
=======
	virtual void playerEffect(std::shared_ptr<Player>) = 0;
	bool isMortgaged();
	void setMortgaged();
	void setUnmortgaged();
	virtual void mortgageBy(Player * player) = 0; // property mortaged by player
	virtual void unmortgageBy(Player * player) = 0; // property unmortaged by plater
>>>>>>> 0e52b58418b97fca2b539f421348d294fe7ccf57
};

class Auction {
public:
	Property* p;
	Auction(Property& prop) : p{ &prop } {}
};

#endif


#ifndef _SQUARE_
#define _SQUARE_

#include <vector>
#include <string>

class Player;


class Square {
	std::vector<Player*> currPlayers;
	std::string name;
public:
	Square(std::string);
	std::vector<Player*> getPlayers();
	std::string getName();
	virtual void playerEffect(Player&) = 0;
};

#endif


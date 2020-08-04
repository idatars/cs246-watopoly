#ifndef _BOARD_
#define _BOARD_

#include <vector>
#include <memory>
#include <iostream>
#include "square.h"
#include "property.h"
#include "upgradable.h"
#include "residence.h"
#include "gym.h"
#include "slc.h"
#include "nh.h"
#include "osap.h"
#include "tuition.h"
#include "timsline.h"
#include "goosenesting.h"
#include "gototims.h"
#include "coopfee.h"

class Square;

class Board {
	//friend istream& operator>>(istream& in, Board b);
	//friend ostream& operator<<(ostream& in, Board b);
	std::vector<std::shared_ptr<Square>> squares;
	std::vector<std::shared_ptr<Player>> players;
	int currplayer = 0;
	int numplayers = 0;
public:
	//Board();
	void newBoard(std::vector<std::shared_ptr<Player>> p);
	void setPlayers(std::vector<std::shared_ptr<Player>>);
	void move(int i); // currplayer rolls dice, moves squares, and as the effect of the square applied on them
	std::string peek(int); // returns the name of the square at i
	std::shared_ptr<Player> currentPlayer();
	//void endturn();
	std::shared_ptr<Square> getSquare(int i);
};

//std::istream& operator>>(std::istream& in, Board b);

//std::ostream& operator<<(std::ostream& in, Board b);

#endif

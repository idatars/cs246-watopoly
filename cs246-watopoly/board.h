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
	friend std::istream& operator>>(std::istream& in, Board &b);
	friend std::ostream& operator<<(std::ostream& out, Board &b);
	std::vector<std::shared_ptr<Square>> squares;
	std::vector<std::shared_ptr<Player>> players;
	std::vector<std::shared_ptr<Property>> properties;
	int currplayer = 0;
	int numplayers = 0;
	int totalcups = 0;
public:
	//Board();
	void newBoard(std::vector<std::shared_ptr<Player>> &p);
	void setPlayers(std::vector<std::shared_ptr<Player>> &p);
	void move(int i); // currplayer rolls dice, moves squares, and as the effect of the square applied on them
	std::string peek(int); // returns the name of the square at i
	std::shared_ptr<Player> currentPlayer();
	void endturn();
	std::shared_ptr<Square> getSquare(int i);
	void addCup();
	void useCup();
	// if trade() return false, ask p1 if he wants to trade again
	bool trade(std::string &from, std::string &to, std::string &give, std::string &receive); 
	void printAssets(std::shared_ptr<Player> &p1);
	std::vector<std::string> getAssets(std::shared_ptr<Player> &p1);
	std::shared_ptr<Property> getProperty(std::string &name);
};

std::istream& operator>>(std::istream& in, Board &b);

std::ostream& operator<<(std::ostream& out, Board &b);

#endif

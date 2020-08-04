#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include <string>
#include <memory>

class Residence;
class Upgradable;
class Gym;

class Player {
	std::string name;
	char piece;
	int pos = 0;
	int money = 1500;
	std::vector<std::shared_ptr<Residence>> rez;
	std::vector<std::shared_ptr<Upgradable>> upgradables;
	std::vector<std::shared_ptr<Gym>> gyms;
	int cups = 0;
	bool tims = false;
	int turnsInTims = 0;
public:
	Player(std::string& name, char piece);
	std::string getName();
	char getPiece();

	int getPos();
	void setPos(int);

	int getMoney();
	void withdrawMoney(int);
	void addMoney(int);

	std::vector<std::shared_ptr<Residence>> getRez();
	std::vector<std::shared_ptr<Upgradable>> getUpgradables();
	std::vector<std::shared_ptr<Gym>> getGyms();
	void buyUpgradable(Upgradable&);
	void buyResidence(Residence&);
	void buyGym(Gym&);

	int getCups();
	void addCup();
	void useCup();
	void setInTims(bool);
	bool inTims();
	int turnsinTims();
	void resetTims();

	int worth();
};

class outOfMoney {

};

#endif

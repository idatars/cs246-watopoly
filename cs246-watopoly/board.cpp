#include "board.h"
#include <string>
#include "monopolyblock.h"
#include <algorithm>
#include <sstream>
void Board::newBoard(std::vector<std::shared_ptr<Player>> &p) {
	squares.clear();
	players.clear();
	players = p;
	numplayers = p.size();

	std::shared_ptr<MonopolyBlock> Arts1(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Arts2(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Eng(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Health(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Env(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Sci1(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Sci2(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Math(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Residences(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Gyms(new MonopolyBlock);


	squares.emplace_back(new OSAP()); // 0
	squares.emplace_back(new Upgradable("AL", 40, 50, 2, 10, 30, 90, 160, 250, Arts1)); // 1
	squares.emplace_back(new SLC(*this)); // 2
	squares.emplace_back(new Upgradable("ML", 60, 50, 4, 20, 60, 180, 320, 450, Arts1)); // 3
	squares.emplace_back(new Tuition()); // 4
	squares.emplace_back(new Residence("MKV", Residences)); // 5
	squares.emplace_back(new Upgradable("ECH", 100, 50, 6, 30, 90, 270, 400, 550, Arts2)); //6
	squares.emplace_back(new NH()); // 7, NH
	squares.emplace_back(new Upgradable("PAS", 100, 50, 6, 30, 90, 270, 400, 550, Arts2)); // 8
	squares.emplace_back(new Upgradable("HH", 120, 50, 8, 40, 100, 300, 450, 600, Arts2)); // 9
	squares.emplace_back(new TimsLine()); // 10
	squares.emplace_back(new Upgradable("RCH", 140, 100, 10, 50, 150, 450, 625, 750, Eng)); // 11
	squares.emplace_back(new Gym("PAC", Gyms)); // 12
	squares.emplace_back(new Upgradable("DWE", 140, 100, 10, 50, 150, 450, 625, 750, Eng)); // 13
	squares.emplace_back(new Upgradable("CPH", 160, 100, 12, 60, 180, 500, 700, 900, Eng)); // 14
	squares.emplace_back(new Residence("UWP", Residences)); // 15
	squares.emplace_back(new Upgradable("LHI", 180, 100, 14, 70, 200, 550, 750, 950, Health)); // 16
	squares.emplace_back(new SLC(*this)); // 17, SLC
	squares.emplace_back(new Upgradable("BMH", 180, 100, 14, 70, 200, 550, 750, 950, Health)); // 18
	squares.emplace_back(new Upgradable("OPT", 200, 100, 16, 80, 220, 600, 800, 1000, Health)); // 19
	squares.emplace_back(new GooseNesting()); // 20
	squares.emplace_back(new Upgradable("EV1", 220, 150, 18, 90, 250, 700, 875, 1050, Env)); // 21
	squares.emplace_back(new NH()); // 22, NH
	squares.emplace_back(new Upgradable("EV2", 220, 150, 18, 90, 250, 700, 875, 1050, Env)); // 23
	squares.emplace_back(new Upgradable("EV3", 240, 150, 20, 100, 300, 750, 925, 1100, Env)); // 24
	squares.emplace_back(new Residence("V1", Residences)); // 25
	squares.emplace_back(new Upgradable("PHYS", 260, 150, 22, 110, 330, 800, 975, 1150, Sci1)); // 26
	squares.emplace_back(new Upgradable("B1", 260, 150, 22, 110, 330, 800, 975, 1150, Sci1)); // 27
	squares.emplace_back(new Gym("CIF", Gyms)); // 28
	squares.emplace_back(new Upgradable("B2", 280, 150, 24, 120, 360, 850, 1025, 1200, Sci1)); // 29
	squares.emplace_back(new GoToTims()); // 30
	squares.emplace_back(new Upgradable("EIT", 300, 200, 26, 130, 390, 900, 1100, 1275, Sci2)); // 31
	squares.emplace_back(new Upgradable("ESC", 300, 200, 26, 130, 390, 900, 1100, 1275, Sci2)); // 32
	squares.emplace_back(new SLC(*this)); // 33, SLC
	squares.emplace_back(new Upgradable("C2", 350, 200, 28, 150, 450, 1000, 1200, 1400, Sci2)); // 34
	squares.emplace_back(new Residence("REV", Residences)); //35
	squares.emplace_back(new NH()); //36, NH
	squares.emplace_back(new Upgradable("MC", 350, 200, 35, 175, 500, 1100, 1300, 1500, Math)); // 37
	squares.emplace_back(new CoopFee()); // 38
	squares.emplace_back(new Upgradable("DC", 400, 200, 50, 200, 600, 1400, 1700, 2000, Math)); // 39

	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[1]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[3]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[5]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[6]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[8]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[9]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[11]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[12]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[13]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[14]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[15]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[16]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[18]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[19]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[21]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[23]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[24]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[25]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[26]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[27]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[28]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[29]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[31]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[32]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[34]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[35]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[37]));
	properties.emplace_back(std::dynamic_pointer_cast<Property>(squares[39]));
}

void Board::setPlayers(std::vector<std::shared_ptr<Player>> &p){
	players = p;
}

void Board::move(int i) {
	if (i + players[currplayer]->getPos() <= 39) {
		players[currplayer]->setPos(players[currplayer]->getPos() + i);
		std::cout << "You are now on " << peek(players[currplayer]->getPos()) << "\n";
		squares[players[currplayer]->getPos()]->playerEffect(players[currplayer]);
	}
	else {
		players[currplayer]->setPos((players[currplayer]->getPos() + i) % 40);
		std::cout << "You collect $200 from OSAP\n";
		players[currplayer]->addMoney(200);
		std::cout << "You are now on " << peek(players[currplayer]->getPos()) << "\n";
		squares[players[currplayer]->getPos()]->playerEffect(players[currplayer]);
	}
}

std::string Board::peek(int i) {
	return squares[i]->getName();
}

std::shared_ptr<Player> Board::currentPlayer() {
	return players[currplayer];
}

void Board::endturn() {
	currplayer = (currplayer + 1) % numplayers;
}

std::shared_ptr<Square> Board::getSquare(int i) {
	return squares[i];
}

void Board::addCup()
{
	++totalcups;
}

void Board::useCup()
{
	--totalcups;
}

std::istream& operator>>(std::istream& in, Board &b) {
	//need to check if file ended early! so we can throw. put the inputs in a try bracket and throw 
	std::vector<std::shared_ptr<Player>> newPlayers;
	in >> b.numplayers;

	std::string name;
	int totalCups = 4; // ADD THIS IN LATER (done)
	char piece;
	int cups = 0; // you can only have 4 cups
	int money = 0;
	int position = 0;
	int inTimsLine = 0;
	int turnsInTims = -1;
	for (int i = 0; i < b.numplayers; ++i) {
		in >> name;
		in >> piece;
		in >> cups;
		in >> money;
		in >> position;

		if (position == 10) {
			in >> inTimsLine;
			if (inTimsLine == 1) {
				in >> turnsInTims;
			}
		}
		std::shared_ptr<Player> newPlayer = std::make_shared<Player>(name, piece);
		newPlayer->setPos(position);
		newPlayer->withdrawMoney(1500);
		newPlayer->addMoney(money); 
		for (int i = 0; i < cups; ++i) {
			if (totalCups == 0) {
				break;
			}
			newPlayer->addCup();
			--totalCups;
		}
		newPlayers.emplace_back(newPlayer);
	}//making all the players!
	b.newBoard(newPlayers);

	std::string property;
	std::string owner;
	int improvementLevel;

	for (int i = 0; i < b.properties.size(); ++i) {
		in >> property;
		in >> owner;
		in >> improvementLevel;
		std::shared_ptr<Player> getPlayer;
		for (int i = 0; i < b.players.size(); ++i) {
			if (b.players[i]->getName() == owner) {
				getPlayer = b.players[i];
				break;
			}
		}
		if (owner != "BANK"){
			b.properties[i]->setOwner(getPlayer);
			getPlayer->addToWorth(b.properties[i]->getCost());
			b.properties[i]->setImprovements(improvementLevel);
		}
		/*if (i == 28 || i == 12) {
			getPlayer->buyGym(*(std::dynamic_pointer_cast<Gym>(b.properties[i])));
		}//if its a gym
		else if (i == 5 || i == 15 || i == 25 || i == 35) {
			//getPlayer->buyResidence();
		}//if its a rez
		else {
			//getPlayer->buyUpgradable();
		}*/
		//add net worth, add monopoly blocks
	}
	return in;
}// load

std::ostream& operator<<(std::ostream& out, Board &b) {
	out << b.numplayers << std::endl;
	int currPlayer = b.currplayer;
	int counter = 0;
	while (counter < b.numplayers) {
		if (currPlayer == b.numplayers) {
			currPlayer = 0;
		}
		else {
			out << b.players[currPlayer]->getName() << " " << b.players[currPlayer]->getPiece() << " ";
			out << b.players[currPlayer]->getCups() << " " << b.players[currPlayer]->getMoney() << " ";
			out << b.players[currPlayer]->getPos() << " ";
			if (b.players[currPlayer]->getPos() == 10) {
				if (b.players[currPlayer]->inTims()) {
					out << "1 " << b.players[currPlayer]->turnsinTims();
				}
				else {
					out << " 0";
				}
			}
			out << std::endl;
			++counter;
			++currPlayer;
		}
	}
	for (int i = 0; i < b.properties.size(); ++i) {
		out << b.properties[i]->getName() << " ";
		if (b.properties[i]->getOwner() == nullptr) {
			out << "BANK ";
		}
		else {
			out << b.properties[i]->getOwner()->getName() << " ";
		}
		if (b.properties[i]->isMortgaged()) {
			out << "-1" << std::endl;
		}
		else {
			out << b.properties[i]->getImprovements() << std::endl;
		}
	}
	return out;
}//save


#include "board.h"
#include <string>
#include "monopolyblock.h"
#include <sstream>
#include <algorithm>
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

bool Board::trade(std::string &from, std::string &to, std::string &give, std::string &receive) {
	std::shared_ptr<Player> tradingTo;
	std::shared_ptr<Player> tradingFrom;
	for (auto player : players){
		if (player->getName() == to) {
			tradingTo = player;
		}
		if (player->getName() == from) {
			tradingFrom = player;
		}
	}
	std::vector<std::string> propertyOfTradingTo = getAssets(tradingTo);
	std::vector<std::string> propertyOfTradingFrom = getAssets(tradingFrom);


	//checking the give string
	int given;
	bool givingMoney = false;
	std::string giveProperty;
	std::shared_ptr<Property> giving;
	try {
		given = std::stoi(give);
		if (given > tradingFrom->getMoney()) {
			std::cout << "You do not have enough money to offer this trade!" << std::endl;
			std::cout << "Your balace is: $" << tradingFrom->getMoney() << std::endl; 
			return false;
		}
		givingMoney = true;
	}
	catch (...){
		giveProperty = give;
		int owned = count(propertyOfTradingFrom.begin(), propertyOfTradingFrom.end(), giveProperty);
		if (owned != 1) {
			std::cout << "You do not own " << give << "." << std::endl;
			return false;
		}
		giving = getProperty(giveProperty);
		if (giving->getImprovements() != 0) {
			std::cout << "You can't trade a property that has improvements on it!" << std::endl;
			return false;
		}
	}
	
	//checking the receiving string
	int receiving;
	bool receivedMoney = false;
	std::string receiveProperty;
	std::shared_ptr<Property> receivingProperty;
	try {
		receiving = std::stoi(receive);
		if (givingMoney == true) {
			std::cout << "You cannot trade money for money." << std::endl;
			return false;
		}
		if (receiving > tradingTo->getMoney()) {
			std::cout << to << " does not have enough money." << std::endl;
			std::cout << to << "'s balance: $" << tradingTo->getMoney() << std::endl;
			return false;
		}
	}
	catch (...) {
		receiveProperty = receive;
		int owned = count(propertyOfTradingTo.begin(), propertyOfTradingTo.end(), receiveProperty);
		if (owned != 1) {
			std::cout << to << " does not own " << give << "." << std::endl;
			return false;
		}
		receivingProperty = getProperty(receiveProperty);
		if (receivingProperty->getImprovements() != 0) {
			std::cout << "You can't trade a property that has improvements on it!" << std::endl;
			return false;
		}
	}

	std::cout << to << ", would you like to accept this offer? Enter \"Yes\" or \"No\":" << std::endl;
	std::string input;
	while (true) {
		std::cin >> input;
		if (input == "Yes" || input == "yes") {
			giving->setOwner(tradingTo);
			tradingFrom->addToWorth(-1 * giving->getCost());
			tradingTo->addToWorth(giving->getCost());

			receivingProperty->setOwner(tradingFrom);
			tradingFrom->addToWorth(receivingProperty->getCost());
			tradingTo->addToWorth(-1 * receivingProperty->getCost());

			std::cout << "The trade has been accepted!" << std::endl;
			std::cout << to << " has received the following:" << std::endl;
			if (givingMoney == true) {
				std::cout << "$" << give << std::endl;
			}
			else {
				std::cout << "Property: " << give << std::endl;
			}

			std::cout << from << " has received the following:" << std::endl;
			if (receivedMoney == true) {
				std::cout << "$" << receive << std::endl;
			}
			else {
				std::cout << "Property: " << receive << std::endl;
			}
			return true;
		}
		else if (input == "No" || input == "No") {
			return false;
		}
		else {
			std::cout << "Please enter \"Yes\" or \"No\":" << std::endl;
		}
	}
	

}

std::shared_ptr<Property> Board::getProperty(std::string &name) {
	for (auto property : properties) {
		if (property->getName() == name) {
			return property;
		}
	}
}

void Board::printAssets(std::shared_ptr<Player> &p1) {
	std::cout << p1->getName() <<" owns the following properties:" << std::endl;
	for (auto i : properties) {
		if (i->getOwner()->getName() == p1->getName()) {
			std::cout << i->getName() << std::endl;
		}
	}
}

std::vector<std::string> Board::getAssets(std::shared_ptr<Player> &p1) {
	std::vector<std::string> assets; 
	for (auto i : properties) {
		if (i->getOwner()->getName() == p1->getName()) {
			assets.emplace_back(i->getName());
		}
	}
	return assets;
}

void Board::getAllAssets() {
	for (auto p : players) {
		std::cout << "Money: $" << p->getMoney() << std::endl;
		std::cout << "Roll Up the Rim Cups: " << p->getCups() << std::endl;
		//listing properties of player now
		for (auto property : properties) {
			if (property->getOwner()->getName() == p->getName()) {
				std::cout << property->getName() << std::endl;
			}
		}
		std::cout << "Total Worth: $" << p->worth() << std::endl;
	}
}

/*void Board::bankrupt(){
	std::shared_ptr<Player> player = currentPlayer();
	player->withdrawMoney(player->getMoney());
	totalcups += player->getCups();
	while (player->getCups() != 0) {
		player->useCup();
	}
	for (auto p : properties) {
		if (p->getOwner()->getName() == player->getName()) {
			p->setOwner(nullptr);
		}
	}
	std::cout << player->getName() << ", you are now bankrupt. Thanks for playing!" << std::endl;
	auto itToPlayer = find(players.begin(), players.end(), player);
	players.erase(itToPlayer);
}*/

void Board::startAuction(std::string &property) {
	std::shared_ptr<Property> prop = getProperty(property);
	int highestBid = 0;
	int currWinner;
	int playersLeft = numplayers;
	bool stillIn[numplayers];
	
	//initializing players who can participate in auction
	std::cout << "The auction will now begin for: " << property << "." << std::endl;
	std::cout << "All players are able to participate and the bidding will start at: $" << highestBid << "." << std::endl;
	
	for (int i = 0; i < numplayers; ++i) {
		stillIn[i] = true;
	}

	bool won = false;
	bool tryAgain = false;
	while (!won) {
		int curr = currplayer;
		int counter = 0;
		while (counter < numplayers) {
			if (curr == numplayers) {
				curr = 0;
			}
			if (stillIn[curr] == true){
				if (players[curr]->getMoney() < highestBid) {
					std::cout << players[curr]->getName() << ", you have been automatically withdrawn from this auction due to a lack of funds." << std::endl;
					stillIn[curr] = false;
					break;
				}
				std::cout << players[curr]->getName() << ", it is your turn. The current bid is: $" << highestBid << std::endl;
				std::cout << "Place your bid or enter \"Withdraw\" to withdraw from this auction:" << std::endl;
				std::string input;
				while (true) {
					try {
						std::cin >> input;
						if (input == "Withdraw" || input == "withdraw") {
							stillIn[curr] = false;
							--playersLeft;
							std::cout << players[curr]->getName() << ", you have withdrawed from this auction." << std::endl;
						}
						else {
							int bid = std::stoi(input);
							if (bid > highestBid) {
								if (bid > players[curr]->getMoney()) {
									std::cout << "The bid you have placed is higher than your balance." << std::endl;
									tryAgain = true;
									throw;
								}
								currWinner = curr;
								highestBid = bid;
								std::cout << players[curr]->getName()  << ", you have the current highest bid of: $" << highestBid << std::endl;
								break;
							}
							else {
								std::cout << "Your bid is not higher than the currect highest bid." << std::endl;
								tryAgain = true;
								throw;
							}
						}
					}
					catch(...) {
						if (tryAgain == true) {
							std::cout << "Enter a new bid or enter \"Withdraw\" to withdraw from this auction:" << std::endl;
							tryAgain = false;
						}
						else {
							std::cout << "That is not a correct input!" << std::endl;
							std::cout << "Place your bid or enter \"Withdraw\" to withdraw from this auction:" << std::endl;
						}
					}		
				}
			}
			if (playersLeft == 1) { // if one player left then they wins
				won = true;
				break;
			}
			++counter;
			++curr;
		}
	}
	std::cout << players[currWinner] << "has won the auction for " << property << " at a bid of: $" << highestBid << std::endl;
	players[currWinner]->withdrawMoney(highestBid);
	players[currWinner]->addToWorth(prop->getCost());
	prop->setOwner(players[currWinner]);
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


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "board.h"
#include "exception.h"
#include <algorithm>
int main(int argc, char *argv[]) {
	bool testing = false;
	std::string infile = "";

	for (int i = 0; i < argc; ++i) {
		std::string arg = argv[i];
		if (arg == "-testing") {
			testing = true;
		}
		if (arg == "-load") {
			if (i + 1 < argc) infile = argv[i + 1];
			else std::cerr << "No input file given" << std::endl;
		}
	}

	Board b;
	std::vector<std::shared_ptr<Player>> players;
	int playersnum = 0;

	if (infile != "") {
		std::ifstream ifs;
		ifs.open(infile);
		playersnum = ifs.peek() - '0';
		ifs >> b;
	}
	else {
		std::cout << "Please enter the number of players (Minimum of 2 players required): ";
		std::string input;
		while (1) {
			try {
				std::cin >> input;
				playersnum = std::stoi(input);
				if (playersnum < 2) {
					std::cout << "Please enter a number greater than 1: ";
				}
				else {
					break;
				}
			}
			catch (...) {
				std::cout << "Please enter a number greater than 1: ";
			}
		}
		std::string name;
		std::string c;
		std::vector<char> pieces;
		for (int i = 1; i <= playersnum; ++i) {
			std::cout << "Player" << i << ", please enter your name: ";
			std::cin >> name;
			std::cout << "\n";
			std::cout << "Please choose your character from the following:" << std::endl;
			std::cout << "	Goose | GRT Bus | Tim Hortons Doughnut | Professor | Student | Money | Laptop | Pink Tie:" << std::endl;
			std::cin.ignore();
			while (1) {
				getline(std::cin, c);
				char piece;
				piece = b.getPiece(c);
				if (piece == '0') {
					std::cout << "Please choose a valid character: ";
				}
				else {
					int counter = count(pieces.begin(), pieces.end(), piece);
					if (counter == 0) {
						pieces.emplace_back(piece);
						players.emplace_back(new Player(name, piece));
						break;
					}
					else {
						std::cout << "This piece is already being used, please select a new one!" << std::endl;
					}
					
				}
			}
			std::cout << "\n";
		}
		b.newBoard(players);
		displayBoard(b);
	}

	int currPlayer = 0;
	while (playersnum > 1) {
		std::cout << "It is " << b.currentPlayer()->getName() << "'s turn\n";
		std::string arg;

		// JAIL
		if (b.currentPlayer()->inTims() && b.currentPlayer()->turnsinTims() == 3 && b.currentPlayer()->getCups() > 0) {
			std::cout << "This is your third turn in the DC Tim's Line, you must either\n(a) pay $50, or\n(b) use a Roll Up the Rim Cup (you have "
				<< b.currentPlayer()->getCups() << " cups)\nto get out!\n";
			std::string answer;
			while (1) {
				std::cin >> answer;
				if (answer == "a") {
					b.currentPlayer()->withdrawMoney(50);
					b.currentPlayer()->resetTims();
					std::cout << "Congrats! You are now out of the Tim's Line!\nYou may continue with your turn.\n";
					break;
				}
				else if (answer == "b") {
					b.currentPlayer()->useCup();
					b.currentPlayer()->resetTims();
					std::cout << "Congrats! You are now out of the Tim's Line!\nYou may continue with your turn.\n";
					break;
				}
				else {
					std::cout << "Invalid input! Please enter 'a' or 'b':";
				}
			}
		}
		else if (b.currentPlayer()->inTims() && b.currentPlayer()->turnsinTims() == 3) {
			std::cout << "This is your third turn in the DC Tim's Line, you must pay $50 to get out\n";
			b.currentPlayer()->withdrawMoney(50);
			std::cout << "You are now out of the Tim's line. You may continue with your turn /n";
		}
		else if (b.currentPlayer()->inTims() && b.currentPlayer()->getCups() > 0) {
			std::cout << "You are in the DC Tim's Line! You can either\n(a) try to roll doubles,\n(b) pay $50, or\n(c) use a Roll Up the Rim Cup (you have "
				<< b.currentPlayer()->getCups() << " cups)\nto get out!\n";
			std::string answer;
			while (1) {
				std::cin >> answer;
				if (answer == "a") {
					int first = rand() % 6 + 1;
					int second = rand() % 6 + 1;
					std::cout << "First die: " << first << "\nSecond die: " << second << '\n';
					if (first == second) {
						std::cout << "You have rolled doubles and are now out of the Tim's line!\nYou may continue with your turn.\n";
						b.currentPlayer()->resetTims();
					}
					else {
						std::cout << "You did not roll doubles.\nYou may continue with your turn.\n";
						b.currentPlayer()->stayinTims();
					}
					break;
				}
				else if (answer == "b") {
					b.currentPlayer()->withdrawMoney(50);
					b.currentPlayer()->resetTims();
					std::cout << "Congrats! You are now out of the Tim's Line!\nYou may continue with your turn.\n";
					break;
				}
				else if (answer == "c") {
					b.currentPlayer()->useCup();
					b.currentPlayer()->resetTims();
					std::cout << "Congrats! You are now out of the Tim's Line!\nYou may continue with your turn.\n";
					break;
				}
				std::cout << "Invalid input. Please enter either 'a', 'b', or 'c': ";
			}
		}
		else if (b.currentPlayer()->inTims()) {
			std::cout << "You are in the DC Tim's Line! You can either\n(a) try to roll doubles, or\n(b) pay $50\n to get out\n";
			std::string answer;
			while (1) {
				std::cin >> answer;
				if (answer == "a") {
					int first = rand() % 6 + 1;
					int second = rand() % 6 + 1;
					std::cout << "First die: " << first << "\nSecond die: " << second << '\n';
					if (first == second) {
						std::cout << "You have rolled doubles and are now out of the Tim's line!\nYou may continue with your turn.\n";
						b.currentPlayer()->resetTims();
					}
					else {
						std::cout << "You did not roll doubles.\nYou may continue with your turn.\n";
						b.currentPlayer()->stayinTims();
					}
					break;
				}
				else if (answer == "b") {
					b.currentPlayer()->withdrawMoney(50);
					b.currentPlayer()->resetTims();
					std::cout << "Congrats! You are now out of the Tim's Line!\nYou may continue with your turn.\n";
					break;
				}
				std::cout << "Invalid input. Please enter either 'a' or 'b': ";
			}
		}

		bool rolled = false;
		bool rentToPlayer = false;
		std::shared_ptr<Player> owedTo = nullptr;
		bool moneyOwed = false;
		bool saved = true;
		int amtOwed;
		while (1) {
			std::cin >> arg;
			if (moneyOwed == true) {
				if (b.currentPlayer()->getMoney() >= amtOwed) {
					b.currentPlayer()->withdrawMoney(amtOwed);
					if (rentToPlayer == true) {
						owedTo->addMoney(amtOwed);
					}
					std::cout << "Your amount owed has been paid!" << std::endl;
				}
				else {
					std::cout << "You still owe money to " << owedTo << "," << " you can declare bankruptcy or raise more money." << std::endl;
				}
			}
			if (arg == "roll") {
				if (!b.currentPlayer()->inTims() && !rolled) { // if player is not in jail
					int roll = 0;
					if (testing) {
						try {
							std::cin >> arg;
							roll += stoi(arg);
							std::cin >> arg;
							roll += stoi(arg);
						}
						catch(std::invalid_argument) {
							std::cerr << "Invalid roll numbers. Rolling from scratch\n";
						}
					}
					else {
						roll = (rand() % 6 + 1) + (rand() % 6 + 1);
						std::cout << "You have rolled a " << roll << '\n';
					}
					rolled = true;
					try { b.move(roll); }
					catch (Auction p) {
						b.startAuction(p.p);
					}
					catch (outOfMoney p) {
						amtOwed = p.amountowed;
						if (p.playerowed != nullptr) {
							rentToPlayer = true;
							owedTo = p.playerowed;
							std::cout << b.currentPlayer()->getName() << ", you owe $"<< amtOwed << " to " << p.playerowed->getName() << std::endl;
						}
						else {
							std::cout << b.currentPlayer()->getName() << ", you owe $"<< amtOwed << " to the bank."<< std::endl;
						}
						moneyOwed = true;
						std::cout << "You can choose to delcare bankruptcy by calling the bankrupt command. You can also choose to \
							mortgage/sell your properties to raise enough money to pay the money you owe." << std::endl;
						std::cout << "Note: If you choose to raise money, once it has been raised it will automatically be deducted from your balance." << std::endl;
						std::cout << "You can only use the following commands while you owe money:" << std::endl;
						std::cout << "  improve (sell only)\n  trade\n  mortgage\n  bankrupt\n  assets\n  all" << std::endl;
					}
				}
				else {
					if (b.currentPlayer()->inTims()) {
						std::cout << "You are in the DC Tim's Line and cannot roll!\n";
					}
					else {
						std::cout << "You have already rolled!" << std::endl;
					}
				}
			}
			else if(arg == "p"){
				displayBoard(b);
			}
			else if (arg == "next") {
				if (rolled == false) {
					std::cout << "You haven't rolled yet! Roll first then end your turn." << std::endl;
					continue;
				}
				else if (moneyOwed == true) {
					std::cout << "You still owe money to " << owedTo << "," << " you can declare bankruptcy or raise more money before ending your turn." << std::endl;
				}
				else {
					b.endturn();
					break;
				}
				
			}
			else if (arg == "trade") {
				std::string name;
				std::cin >> name;
				std::string give;
				std::cin >> give;
				std::string receive;
				std::cin >> receive;
				b.trade(b.currentPlayer()->getName(), name, give, receive);
			}
			else if (arg == "improve") {
				std::string prop;
				std::cin >> prop;
				std::string option;
				std::cin >> option;
				if (option == "buy") {
					if (moneyOwed == true) {
						std::cout << "You still owe money to " << owedTo << "," << " you can declare bankruptcy or raise more money." << std::endl;
						continue;
					}
					try {
						auto property = b.findProperty(prop);
						b.currentPlayer()->buyImprovement(property.get());
					}
					catch (Exception e) {
						std::cout << e.getMessage()<<std::endl;
					}
				}
				else if (option == "sell") {
					try {
						auto property = b.findProperty(prop);
						b.currentPlayer()->sellImprovement(property.get());
					}
					catch (Exception e) {
						std::cout << e.getMessage()<<std::endl;
					}
				}
				else std::cout << "Invalid command\n";
			}
			else if (arg == "mortgage") {
				std::string prop;
				std::cin >> prop;
				try {
					auto property = b.findProperty(prop);
					b.currentPlayer()->getMortgage(property.get());
				}
				catch (Exception e) {
					std::cout << e.getMessage() << std::endl;
				}
			}
			else if (arg == "unmortgage") {
				if (moneyOwed == true) {
					std::cout << "You still owe money to " << owedTo << "," << " you can declare bankruptcy or raise more money." << std::endl;
					continue;
				}
				std::string prop;
				std::cin >> prop;
				try {
					auto property = b.findProperty(prop);
					b.currentPlayer()->getUnmortgage(property.get());
				}
				catch (Exception e) {
					std::cout << e.getMessage()<<std::endl;
				}
			}
			else if (arg == "bankrupt") {
				if (moneyOwed == true) {
					std::cout << "You owe $" << amtOwed << " to";
					if (owedTo != nullptr) {
						std::cout << owedTo->getName() << "."<< std::endl;
					}
					else {
						std::cout << "the bank."<< std::endl;
					}
					std::cout << "You can (a) declare bankruptcy, or (b) try and raise money:";
					std::string input;
					while (1) {
						std::cin >> input;
						if (input == "a" || input == "A") {
							if (owedTo != nullptr) {
								b.transferAssets(b.currentPlayer(), owedTo);
							}
							else {
								b.dropout();
							}
							std::cout << "Thanks for playing!" << std::endl;
							break;
						}
						else if (input == "b" || input == "B") {

							break;
						}
						else {
							std::cout << "This is an invalid answer, please enter either 'a' or 'b':";
						}
					}
				}
				else {
					std::cout<< "You don't owe anyone money, you cannot call bankrupt!" << std::endl;
				}
			}
			else if (arg == "assets") {
				b.printAssets(b.currentPlayer());
			}
			else if (arg == "all") {
				b.getAllAssets();
			}
			else if (arg == "save") {
				if (moneyOwed == true) {
					std::cout << "You still owe money to " << owedTo << "," << " you can declare bankruptcy or raise more money before saving." << std::endl;
					continue;
				}
				b.endturn();
				std::ofstream outFile;
				std::string file;
				std::cin >> file;
				outFile.open(file);
				outFile << b;
				std::cout << "Your game has been saved to the following file: " << file << std::endl;
			}
			else if (arg == "quit") {
				if (saved != true) {
					std::cout << "You will be quitting without saving! Are you sure?: ";
					std::string input;
					while (1) {
						std::cin >> input;
						if (input == "yes" || input == "Yes") {
							std::cout << "Thanks for playing!" << std::endl;
							return 0;
						}
						else if(input == "no" || input == "No") {
							std::cout << "You have chosen not to quit without saving." << std::endl;
						}
						else {
							std::cout << "Incorrect input, please enter Yes or No: ";
						}
					}
				}
				else {
					std::cout << "Thanks for playing!" << std::endl;
					return 0;
				}
			}
		}
	}
	if (playersnum == 1) {
		std::cout << players[1]->getName() << " is the winner!\nCongratulations, you win bragging rights and eternal glory!\n";
	}
	std::cout << "Thanks for playing! :D\n";
	return 0;
}

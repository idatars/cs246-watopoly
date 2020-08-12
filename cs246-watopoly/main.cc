#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "board.h"
#include "exception.h"

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
		std::cout << "Please enter the number of players: ";
		std::cin >> playersnum;
		while (playersnum < 2 && !testing) {
			std::cout << "Error: number of players must be greater than 2\nPlease enter the number of players: ";
			std::cin >> playersnum;
		}
		std::string name;
		char c;
		for (int i = 1; i <= playersnum; ++i) {
			std::cout << "Player" << i << ", please enter your name: ";
			std::cin >> name;
			std::cout << "Player" << i << ", please enter your character: ";
			std::cin >> c;
			players.emplace_back(new Player(name, c));
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
		while (1) {
			std::cin >> arg;
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
						roll = rand() % 6 + rand() % 6 + 2;
						std::cout << "You have rolled a " << roll << '\n';
					}
					rolled = true;
					try { b.move(roll); }
					catch (Auction p) {
						b.startAuction(p.p);
					}
					catch (outOfMoney p) {
						std::cout << "You are out of money! You can (a) declare bankruptcy, or (b) try and raise money: ";
						std::string ans;
						while (1) {
							std::cin >> ans;
							if (ans == "a") {
								if (p.playerowed == nullptr) { // player owes the bank
									b.dropout();
								}
								else { // player owes another player
									b.transferAssets(b.currentPlayer(), p.playerowed);
								}
								break;
							}
							else if (ans == "b") {
								std::cout << "You may now attempt to mortgage properties and sell improvements. Or, enter 'end' to drop out\n";
								break;
							}
							else std::cout << "Invalid argument. Please enter either 'a' or 'b': ";
						}
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
				b.endturn();
				break;
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
					try {
						b.findProperty(prop)->improve(b.currentPlayer().get());
					}
					catch (Exception e) {
						std::cout << e.getMessage();
					}
				}
				else if (option == "sell") {
					try {
						b.findProperty(prop)->sellimprove(b.currentPlayer().get());
					}
					catch (Exception e) {
						std::cout << e.getMessage();
					}
				}
				else std::cout << "Invalid command\n";
			}
			else if (arg == "mortgage") {
				std::string prop;
				std::cin >> prop;
				try {
					b.findProperty(prop)->mortgageBy(b.currentPlayer().get());
				}
				catch (Exception e) {
					std::cout << e.getMessage();
				}
			}
			else if (arg == "unmortgage") {
				std::string prop;
				std::cin >> prop;
				try {
					b.findProperty(prop)->unmortgageBy(b.currentPlayer().get());
				}
				catch (Exception e) {
					std::cout << e.getMessage();
				}
			}
			else if (arg == "bankrupt") std::cout << "You do not have access to this command right now!\n";
			else if (arg == "assets") {
				b.printAssets();
			}
			else if (arg == "all") {
				b.getAllAssets();
			}
			else if (arg == "save") {
				std::ofstream outFile;
				std::string file;
				std::cout << "enter save file name: ";
				std::cin >> file;
				outFile.open(file);
				outFile << b;
				playersnum = 0;
				break;
			}
		}
	}
	std::cout << "Thanks for playing!\n";
}
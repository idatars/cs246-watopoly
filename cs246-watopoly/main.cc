#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "board.h"

int main(int argc, char *argv[]) {
	bool testing = false;
	std::string infile = "help me";

	for (int i = 0; i < argc; ++i) {
		if (argv[i] == "-testing") testing = true;
		if (argv[i] == "-load") {
			if (i + 1 < argc) infile = argv[i + 1];
			else std::cerr << "No input file given";
		}
	}

	Board b;
	int playersnum = 0;

	if (infile != "") {
		std::ifstream ifs;
		ifs.open(infile);
		playersnum = ifs.peek() - '0';
		//ifs >> b;
	}
	else {
		std::vector<std::shared_ptr<Player>> players;
		std::cout << "Please enter the number of players: ";
		std::cin >> playersnum;
		while (playersnum < 2) {
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
	}


	// GAMEPLAY ////////////////////////////////

	int currPlayer = 0;
	while (playersnum > 1) {
		std::cout << "It is " << b.currentPlayer()->getName() << "'s turn";
		std::string arg;
		if (b.currentPlayer()->inTims() && b.currentPlayer()->turnsinTims() == 3 && b.currentPlayer()->getCups() > 0) {
			std::cout << "This is your third turn in the DC Tim's Line, you must either\n(a) pay $50, or\n(b) use a Roll Up the Rim Cup (you have "
				<< b.currentPlayer()->getCups() << " cups)\nto get out!\n";
			std::string answer;
			while (1) {
				std::cin >> answer;
				if (answer == "a") {
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
			
		}
		if (arg == "roll") {
			int roll = rand() % 6 + 1 + rand() % 6 + 1;
			b.move(roll);

		}
	}
}
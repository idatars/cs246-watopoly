#include "gym.h"
#include <iostream>

Gym::Gym(std::string name) : Property(name, 150) {}

int Gym::usageFees() {
	if (getOwner()->getGyms().size() == 2) return 10 * (rand() % 6 + 1 + rand() % 6 + 1);
	else return 4 * (rand() % 6 + 1 + rand() % 6 + 1);
}

void Gym::playerEffect(Player& p) {
	if (getOwner() == nullptr) {
		std::string answer;
		std::cout << "Would you like to purchase " << getName() << " (Gym) for $" << getCost() << "? ";
		while (1) {
			std::cin >> answer;
			if (answer == "yes") {
				p.buyGym(*this);
				break;
			}
			else if (answer == "no") {
				throw Auction(*this);
				break;
			}
			else {
				std::cout << "Invalid input. Please enter either 'yes' or 'no':";
			}
		}
	}
	else if (getOwner()->getName() == p.getName()) std::cout << "You own this property. Welcome home :)";
	else {
		p.withdrawMoney(usageFees());
	}
}

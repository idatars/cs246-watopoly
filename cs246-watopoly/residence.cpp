#include "residence.h"
#include <iostream>

Residence::Residence(std::string name) : Property(name, 200) {}

int Residence::getRent() {
    return rent[getOwner()->getRez().size()];
}

void Residence::playerEffect(Player& p) {
	if (getOwner() == nullptr) {
		std::string answer;
		std::cout << "Would you like to purchase " << getName() << " (Residence) for $" << getCost() << "? ";
		while (1) {
			std::cin >> answer;
			if (answer == "yes") {
				p.buyResidence(*this);
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
		p.withdrawMoney(getRent());
	}
}
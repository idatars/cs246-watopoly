#include "upgradable.h"
#include <iostream>

Upgradable::Upgradable(std::string name, int c, int ic, int t0, int t1, int t2, int t3, int t4, int t5, std::shared_ptr<MonopolyBlock> b) :
    Property(name, c),
    improvementCost{ ic },
    tuition{ t0, t1, t2, t3, t4, t5 },
	block{ b } {
	b->getMembers().push_back(this);
}

int Upgradable::getImprovementCost() {
    return improvementCost;
}

int Upgradable::getImprovements() {
    return improvements;
}

int Upgradable::getTuition() {
    for (std::vector<std::shared_ptr<Upgradable>>::iterator it = getOwner()->getUpgradables().begin(); it != getOwner()->getUpgradables().end(); ++it) {
        if ((*it)->getOwner()->getName() != getOwner()->getName()) return tuition[0];
    }
    if (getImprovements() == 0) return 2 * tuition[0];
    return tuition[improvements];
}

void Upgradable::playerEffect(Player& p) {
	if (getOwner() == nullptr) {
		std::string answer;
		std::cout << "Would you like to purchase " << getName() << " (Academic Building) for $" << getCost() << "? ";
		while (1) {
			std::cin >> answer;
			if (answer == "yes") {
				p.buyUpgradable(*this);
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
		p.withdrawMoney(getTuition());
	}
}
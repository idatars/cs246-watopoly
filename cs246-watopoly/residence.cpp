#include "residence.h"
#include <iostream>
#include "exception.h"

Residence::Residence(std::string name) : Property(name, 200) {}

int Residence::getRent() {
    return rent[getOwner()->getRez().size()];
}

void Residence::playerEffect(std::shared_ptr<Player> p) {
	if (getOwner() == nullptr) {
		std::string answer;
		std::cout << "Would you like to purchase " << getName() << " (Residence) for $" << getCost() << "? ";
		while (1) {
			std::cin >> answer;
			if (answer == "yes") {
				p->buyResidence(*this);
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
	else if (getOwner()->getName() == p->getName()) std::cout << "You own this property. Welcome home :)";
	else {
		p->withdrawMoney(getRent());
	}
}

void Residence::mortgageBy(Player * player){
	if(this->isMortgaged()){
		throw(Exception{"You have already mortgaged the property."});
	}try{
		player->addMoney(this->getMortgage());
		this->setMortgaged();
	}catch(Exception & e){
		throw(e);
	}
}

void Residence::unmortgageBy(Player * player){
	if(!this->isMortgaged()){
		throw(Exception{"You have already unmortgaged the property."});
	}try{
		player->withdrawMoney(this->getMortgage() * 6 / 5);
		this->setUnmortgaged();
	}catch(Exception & e){
		throw(e);
	}
}

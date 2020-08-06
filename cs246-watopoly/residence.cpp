#include "residence.h"
#include <iostream>
#include "exception.h"

Residence::Residence(std::string name, std::shared_ptr<MonopolyBlock> b) : Property(name, 200, b) {}

int Residence::getRent() {
    return rent[getBlock()->countOwner(getOwner())];
}

void Residence::playerEffect(std::shared_ptr<Player> p) {
	if (getOwner() == nullptr) {
		std::string answer;
		std::cout << "Would you like to purchase " << getName() << " (Residence) for $" << getCost() << "? ";
		while (1) {
			std::cin >> answer;
			if (answer == "yes") {
				p->withdrawMoney(this->getCost());
				this->setOwner(p);
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
<<<<<<< HEAD
		throw(Exception{"You have already mortaged the property."});
=======
		throw(Exception{"You have already mortgaged the property."});
>>>>>>> improve_mortage
	}try{
		player->addMoney(this->getMortgage());
		this->setMortgaged();
	}catch(Exception & e){
		throw(e);
	}
}

void Residence::unmortgageBy(Player * player){
	if(!this->isMortgaged()){
<<<<<<< HEAD
		throw(Exception{"You have already unmortaged the property."});
=======
		throw(Exception{"You have already unmortgaged the property."});
>>>>>>> improve_mortage
	}try{
		player->withdrawMoney(this->getMortgage() * 6 / 5);
		this->setUnmortgaged();
	}catch(Exception & e){
		throw(e);
	}
}

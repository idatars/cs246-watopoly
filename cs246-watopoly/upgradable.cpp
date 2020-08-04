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

//returns true if the owener of the upgradable forms a monopoly and false otherwise
bool Upgradable::ownMonopoly(){
	Player * owner =  this->getOwner(); 
	if(owner==nullptr){
		return false;
	}
	std::vector<Upgradable*> monopoly_members = block->getMembers();
	std::vector<Upgradable*> player_owned = owner->getUpgradables()
	for(auto it=monopoly_members.begin(); it!=monopoly_members.end();++it){
		//if owner does not own one of the buildings in the monopoly
		if(std::find(player_owned.begin(),player_owned.end(),it)==player_owned.end()){ 
			return false;
		}
	}
	return true;
}

//imporve the building
void Upgradable::improve(Player * player){
	if(player != this->getOwner()){
		throw(Exception{"This building is not yours :("}); // not ur property
	}else if(!this->ownMonopoly()){
		throw(Exception{"You do not own the monopoly, keep tring!"}); // does not own monopoly
	}else if(imporvements == 5){ // improvement number is at max
		throw(Exception{"You have reached the maximum improvement number."});
	}else{ // buy improvement
		try{
			player->withdrawMoney(improvementCost);
			improvements += 1;
		}catch(Exception & e){
			throw(e);
		}
	}
}

void Upgradable::mortage(Player * player){
	if(this->isMortaged()){
		throw(Exception{"You have already mortaged the property."});
	}else if(improvements != 0){
		throw(Exception{"You need to sale all the improvements."});
	}try{
		player->addMoney(this->getMortage());
		this->setMortaged();
	}catch(Exception & e){
		throw(e);
	}
}

void Upgradable::unmortage(Player * player){
	if(!this->isMortaged()){
		throw(Exception{"You have already unmortaged the property."});
	}try{
		player->withdrawMoney(this->getMortage() * 6 / 5);
		this->setUnmortaged();
	}catch(Exception & e){
		throw(e);
	}
}

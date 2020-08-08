#include "upgradable.h"
#include <iostream>
#include "exception.h"
#include <algorithm>

Upgradable::Upgradable(std::string name, int c, int ic, int t0, int t1, int t2, int t3, int t4, int t5, std::shared_ptr<MonopolyBlock> b) :
    Property(name, c, b),
    improvementCost{ ic },
    tuition{ t0, t1, t2, t3, t4, t5 } {
	b->getMembers().push_back(this);
}

int Upgradable::getImprovementCost() {
    return improvementCost;
}

int Upgradable::getImprovements() {
    return improvements;
}

void Upgradable::setImprovements(int level) {
	improvements = level;
}

int Upgradable::getTuition() {
    if (ownMonopoly() && getImprovements() == 0) return 2 * tuition[0];
    return tuition[improvements];
}

void Upgradable::playerEffect(std::shared_ptr<Player> p) {
	if (getOwner() == nullptr) {
		std::string answer;
		std::cout << "Would you like to purchase " << getName() << " (Academic Building) for $" << getCost() << "? ";
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
		p->withdrawMoney(getTuition());
	}
}

//returns true if the owener of the upgradable forms a monopoly and false otherwise
bool Upgradable::ownMonopoly(){
	return getBlock()->countOwner(getOwner()) == getBlock()->getMembers().size();
	
	/*Player * owner =  this->getOwner(); 
	if(owner==nullptr){
		return false;
	}
	std::vector<Upgradable*> monopoly_members = block->getMembers();
	std::vector<std::shared_ptr<Upgradable>> player_owned = owner->getUpgradables();
	for(auto it=monopoly_members.begin(); it!=monopoly_members.end();++it){
		//if owner does not own one of the buildings in the monopoly
		bool has_upgradable = false;
		for(auto it2=player_owned.begin(); it2!=player_owned.end();++it2){
			if((*it2)->getName() == (*it)->getName()){
				has_upgradable = true;
				break;
			}
		}
		if(!has_upgradable){
			return false;
		}
	}
	return true;
	*/
}

//imporve the building
void Upgradable::improve(Player * player){
	if(player != this->getOwner().get()){
		throw(Exception{"This building is not yours :("}); // not ur property
	}else if(!this->ownMonopoly()){
		throw(Exception{"You do not own the monopoly, keep tring!"}); // does not own monopoly
	}else if(improvements == 5){ // improvement number is at max
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

void Upgradable::mortgageBy(Player * player){
	if(this->isMortgaged()){
		throw(Exception{"You have already mortgaged the property."});
	}else if(improvements != 0){
		throw(Exception{"You need to sale all the improvements."});
	}try{
		player->addMoney(this->getMortgage());
		this->setMortgaged();
	}catch(Exception & e){
		throw(e);
	}
}

void Upgradable::unmortgageBy(Player * player){
	if(!this->isMortgaged()){
		throw(Exception{"You have already unmortgaged the property."});
	}try{
		player->withdrawMoney(this->getMortgage() * 6 / 5);
		this->setUnmortgaged();
	}catch(Exception & e){
		throw(e);
	}
}

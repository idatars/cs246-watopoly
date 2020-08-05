#include "property.h"

Property::Property(std::string& name, int c, std::shared_ptr<MonopolyBlock> b) :
    Square(name),
    cost{ c },
    mortgage{ c / 2 },
    block{ b }
{}

int Property::getCost() {
    return cost;
}

Player* Property::getOwner() {
    return owner;
}

void Property::setOwner(Player& newowner) {
    owner = &newowner;
}

int Property::getMortgage() {
    return mortgage;
}

bool Property::isMortgaged(){
	return mortgaged;
}

void Property::setMortgaged(){
	mortgaged = true;
}

void Property::setUnmortgaged(){
	mortgaged = false;
}

#include "property.h"

Property::Property(std::string& name, int c) :
    Square(name),
    cost{ c },
    mortgage{ c / 2 }
{}

int Property::getCost() {
    return cost;
}

Player* Property::getOwner() {
    return owner;
}

void Property::setOwner(std::shared_ptr<Player> newowner) {
    owner = &newowner;
}

int Property::getMortgage() {
    return mortgage;
}

bool isMortaged(){
	return mortgaged;
}

void setMortaged(){
	mortgaged = true;
}

void setUnmortaged(){
	mortgaged = false;
}

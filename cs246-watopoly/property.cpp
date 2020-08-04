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

void Property::setOwner(Player& newowner) {
    owner = &newowner;
}

int Property::getMortgage() {
    return mortgage;
}


#include "player.h"
#include <iostream>

Player::Player(std::string& name, char piece) {
	this->name = name;
	this->piece = piece;
}

std::string Player::getName() { return name; }

char Player::getPiece() { return piece; }

int Player::getPos() { return pos; }

void Player::setPos(int i) { pos = i; }

int Player::getMoney() { return money; }

void Player::withdrawMoney(int i) {
	if (i > money) {
		throw outOfMoney();
	}
	money -= i;
}

void Player::addMoney(int i) { money += i; }

std::vector<std::shared_ptr<Residence>> Player::getRez() { return rez; }

std::vector<std::shared_ptr<Upgradable>> Player::getUpgradables() { return upgradables; }

std::vector<std::shared_ptr<Gym>> Player::getGyms() { return gyms; }

int Player::getCups() { return cups; }

void Player::addCup() { ++cups; }

void Player::useCup()
{
	--cups;
}

void Player::buyUpgradable(Upgradable&) {

}

void Player::buyResidence(Residence&) {

}

void Player::buyGym(Gym&) {

}

int Player::worth() {
	return 0;
}

void Player::setInTims(bool b) {
	tims = b;
}

bool Player::inTims()
{
	return tims;
}

int Player::turnsinTims()
{
	return turnsInTims;
}

void Player::resetTims()
{
	turnsInTims = 0;
	tims = false;
}

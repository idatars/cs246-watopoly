#include "tuition.h"
#include <iostream>

Tuition::Tuition() : NonProperty("Tuition") {}

void Tuition::playerEffect(Player& p) {
	std::string answer;
	std::cout << "Would you like to pay (a) $300 or (b) 10% of your total worth? ";
	while (1) {
		std::cin >> answer;
		if (answer == "a") {
			p.withdrawMoney(300);
			break;
		}
		else if (answer == "b") {
			p.withdrawMoney(p.worth());
			break;
		}
		else {
			std::cout << "Invalid answer. Please enter either 'a' or 'b': ";
		}
	}
}

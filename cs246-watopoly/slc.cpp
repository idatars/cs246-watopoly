#include "slc.h"
#include <random>
#include <iostream>


SLC::SLC(Board& board) : NonProperty("SLC"), b{ &board } {}

void SLC::playerEffect(Player& p) {
	int n = rand() % 24;
	if (0 <= n && n <= 2) { // back 3
		p.setPos(p.getPos() - 3);
		std::cout << "You have been moved 3 spaces back!\nYou are now on " << b->peek(p.getPos()) << std::endl;
		b->getSquare(p.getPos())->playerEffect(p);
	}
	else if (3 <= n && n <= 6) { // back 2
		p.setPos(p.getPos() - 3);
		std::cout << "You have been moved 2 spaces back!\nYou are now on " << b->peek(p.getPos()) << std::endl;
		b->getSquare(p.getPos())->playerEffect(p);
	}
	else if (7 <= n && n <= 10) { // back 1
		p.setPos(p.getPos() - 1);
		std::cout << "You have been moved 1 space back!\nYou are now on " << b->peek(p.getPos()) << std::endl;
		b->getSquare(p.getPos())->playerEffect(p);
	}
	else if (11 <= n && n <= 13) { // forward 1
		p.setPos(p.getPos() + 1);
		std::cout << "You have been moved 1 space forward!\nYou are now on " << b->peek(p.getPos()) << std::endl;
		b->getSquare(p.getPos())->playerEffect(p);
	}
	else if (14 <= n && n <= 17) { // forward 2
		p.setPos(p.getPos() + 1);
		std::cout << "You have been moved 2 spaces forward!\nYou are now on " << b->peek(p.getPos()) << std::endl;
		b->getSquare(p.getPos())->playerEffect(p);
	}
	else if (18 <= n && n <= 21) { // forward 3
		p.setPos(p.getPos() + 1);
		std::cout << "You have been moved 2 spaces forward!\nYou are now on " << b->peek(p.getPos()) << std::endl;
		b->getSquare(p.getPos())->playerEffect(p);
	}
	else if (n == 22) { // go to tim's line
		p.setPos(10);
		std::cout << "You have been moved to DC Tim's Line!\n";
		///
	}
	else { // collect osap
		p.setPos(0);
		std::cout << "You have been moved to Collect Osap\n";
		p.addMoney(200);
	}
}

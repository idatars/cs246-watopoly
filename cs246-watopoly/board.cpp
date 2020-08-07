#include "board.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "monopolyblock.h"

void Board::newBoard(std::vector<std::shared_ptr<Player>> p) {
	squares.clear();
	players.clear();
	players = p;
	numplayers = p.size();

	std::shared_ptr<MonopolyBlock> Arts1(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Arts2(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Eng(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Health(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Env(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Sci1(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Sci2(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Math(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Residences(new MonopolyBlock);
	std::shared_ptr<MonopolyBlock> Gyms(new MonopolyBlock);


	squares.emplace_back(new OSAP()); // 0
	squares.emplace_back(new Upgradable("AL", 40, 50, 2, 10, 30, 90, 160, 250, Arts1)); // 1
	squares.emplace_back(new SLC(*this)); // 2
	squares.emplace_back(new Upgradable("ML", 60, 50, 4, 20, 60, 180, 320, 450, Arts1)); // 3
	squares.emplace_back(new Tuition()); // 4
	squares.emplace_back(new Residence("MKV", Residences)); // 5
	squares.emplace_back(new Upgradable("ECH", 100, 50, 6, 30, 90, 270, 400, 550, Arts2)); //6
	squares.emplace_back(new NH()); // 7, NH
	squares.emplace_back(new Upgradable("PAS", 100, 50, 6, 30, 90, 270, 400, 550, Arts2)); // 8
	squares.emplace_back(new Upgradable("HH", 120, 50, 8, 40, 100, 300, 450, 600, Arts2)); // 9
	squares.emplace_back(new TimsLine()); // 10
	squares.emplace_back(new Upgradable("RCH", 140, 100, 10, 50, 150, 450, 625, 750, Eng)); // 11
	squares.emplace_back(new Gym("PAC", Gyms)); // 12
	squares.emplace_back(new Upgradable("DWE", 140, 100, 10, 50, 150, 450, 625, 750, Eng)); // 13
	squares.emplace_back(new Upgradable("CPH", 160, 100, 12, 60, 180, 500, 700, 900, Eng)); // 14
	squares.emplace_back(new Residence("UWP", Residences)); // 15
	squares.emplace_back(new Upgradable("LHI", 180, 100, 14, 70, 200, 550, 750, 950, Health)); // 16
	squares.emplace_back(new SLC(*this)); // 17, SLC
	squares.emplace_back(new Upgradable("BMH", 180, 100, 14, 70, 200, 550, 750, 950, Health)); // 18
	squares.emplace_back(new Upgradable("OPT", 200, 100, 16, 80, 220, 600, 800, 1000, Health)); // 19
	squares.emplace_back(new GooseNesting()); // 20
	squares.emplace_back(new Upgradable("EV1", 220, 150, 18, 90, 250, 700, 875, 1050, Env)); // 21
	squares.emplace_back(new NH()); // 22, NH
	squares.emplace_back(new Upgradable("EV2", 220, 150, 18, 90, 250, 700, 875, 1050, Env)); // 23
	squares.emplace_back(new Upgradable("EV3", 240, 150, 20, 100, 300, 750, 925, 1100, Env)); // 24
	squares.emplace_back(new Residence("V1", Residences)); // 25
	squares.emplace_back(new Upgradable("PHYS", 260, 150, 22, 110, 330, 800, 975, 1150, Sci1)); // 26
	squares.emplace_back(new Upgradable("B1", 260, 150, 22, 110, 330, 800, 975, 1150, Sci1)); // 27
	squares.emplace_back(new Gym("CIF", Gyms)); // 28
	squares.emplace_back(new Upgradable("B2", 280, 150, 24, 120, 360, 850, 1025, 1200, Sci1)); // 29
	squares.emplace_back(new GoToTims()); // 30
	squares.emplace_back(new Upgradable("EIT", 300, 200, 26, 130, 390, 900, 1100, 1275, Sci2)); // 31
	squares.emplace_back(new Upgradable("ESC", 300, 200, 26, 130, 390, 900, 1100, 1275, Sci2)); // 32
	squares.emplace_back(new SLC(*this)); // 33, SLC
	squares.emplace_back(new Upgradable("C2", 350, 200, 28, 150, 450, 1000, 1200, 1400, Sci2)); // 34
	squares.emplace_back(new Residence("REV", Residences)); //35
	squares.emplace_back(new NH()); //36, NH
	squares.emplace_back(new Upgradable("MC", 350, 200, 35, 175, 500, 1100, 1300, 1500, Math)); // 37
	squares.emplace_back(new CoopFee()); // 38
	squares.emplace_back(new Upgradable("DC", 400, 200, 50, 200, 600, 1400, 1700, 2000, Math)); // 39
}

void Board::setPlayers(std::vector<std::shared_ptr<Player>> p){
	players = p;
}

void Board::move(int i) {
	if (i + players[currplayer]->getPos() <= 39) {
		players[currplayer]->setPos(players[currplayer]->getPos() + i);
		std::cout << "You are now on " << peek(players[currplayer]->getPos()) << "\n";
		squares[players[currplayer]->getPos()]->playerEffect(players[currplayer]);
	}
	else {
		players[currplayer]->setPos((players[currplayer]->getPos() + i) % 40);
		std::cout << "You collect $200 from OSAP\n";
		players[currplayer]->addMoney(200);
		std::cout << "You are now on " << peek(players[currplayer]->getPos()) << "\n";
		squares[players[currplayer]->getPos()]->playerEffect(players[currplayer]);
	}
}

std::string Board::peek(int i) {
	return squares[i]->getName();
}

std::shared_ptr<Player> Board::currentPlayer() {
	return players[currplayer];
}

void Board::endturn() {
	currplayer = (currplayer + 1) % numplayers;
}

std::shared_ptr<Square> Board::getSquare(int i) {
	return squares[i];
}

void Board::addCup()
{
	++totalcups;
}

void Board::useCup()
{
	--totalcups;
}



////////////////////////Functions Outside of Class////////////////////////////
std::ostream& operator<<(std::ostream& in, Board b){
	
/*
 #   #  ##  #####  ###   ###   ###  #   #   #
 #   # #  #   #   #   #  #  # #   # #   #   # 
 # # # ####   #   #   #  ###  #   # #    # #
 # # # #  #   #   #   #  #    #   # #     #
 ##### #  #   #    ###   #     ###  ## #  #
*/
	//20 - 30
	in << mult_string("-",100) << std::endl; // 100 '-' by word count
	in << "|" << firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(20))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(21))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(22))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(23))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(24))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Residence>(b.getSquare(25))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(26))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(27))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Gym>(b.getSquare(28))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(29))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(30))) << "|" << std::endl;
	in << "|" << secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(20))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(21))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(22))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(23))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(24))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Residence>(b.getSquare(25))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(26))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(27))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Gym>(b.getSquare(28))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(29))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(30))) << "|" << std::endl;
	in << "|" << thirdline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(20))) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(21))) << "|" << 
		thirdline_print(b.getSquare(22)) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(23))) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(24))) << "|" << 
		thirdline_print(b.getSquare(25)) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(26))) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(27))) << "|" << 
		thirdline_print(b.getSquare(28)) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(29))) << "|" << 
		thirdline_print(b.getSquare(30)) << "|" << std::endl;
	in << "|" << fourthline_print(b.getSquare(20)) << "|" << 
		fourthline_print(b.getSquare(21)) << "|" << 
		fourthline_print(b.getSquare(22)) << "|" << 
		fourthline_print(b.getSquare(23)) << "|" << 
		fourthline_print(b.getSquare(24)) << "|" << 
		fourthline_print(b.getSquare(25)) << "|" << 
		fourthline_print(b.getSquare(26)) << "|" << 
		fourthline_print(b.getSquare(27)) << "|" << 
		fourthline_print(b.getSquare(28)) << "|" << 
		fourthline_print(b.getSquare(29)) << "|" << 
		fourthline_print(b.getSquare(30)) << "|" << std::endl;
	in << "|" << mult_string("-",8) << "|" << mult_string("-",8) << "|" << mult_string("-",8) << 
		"|" << mult_string("-",8) << "|" << mult_string("-",8) << "|" << mult_string("-",8) << 
		"|" << mult_string("-",8) << "|" << mult_string("-",8) << "|" << mult_string("-",8) << 
		"|" << mult_string("-",8) << "|" << mult_string("-",8) << "|" << std::endl;
	// 19 31
	in << "|" << firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(19))) << "|" <<
		mult_string(" ",80) << "|" << 
		 firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(31))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(19))) << "|" <<
		mult_string(" ",80) << "|" << 
		 secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(31))) << "|" << std::endl; 
	in << "|" << thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(19))) << "|" <<
		mult_string(" ",80) << "|" << 
		 thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(31))) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(19)) << "|" <<
		mult_string(" ",80) << "|" << 
		 fourthline_print(b.getSquare(31)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << mult_string(" ",80) << "|" << mult_string("-",8) << "|" << std::endl;
	// 18 32
	in << "|" << firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(18))) << "|" <<
		mult_string(" ",80) << "|" << 
		 firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(32))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(18))) << "|" <<
		mult_string(" ",80) << "|" << 
		 secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(32))) << "|" << std::endl; 
	in << "|" << thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(18))) << "|" <<
		mult_string(" ",80) << "|" << 
		 thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(32))) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(18)) << "|" <<
		mult_string(" ",80) << "|" << 
		 fourthline_print(b.getSquare(32)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << mult_string(" ",80) << "|" << mult_string("-",8) << "|" << std::endl;
	// 17 33
	in << "|" << firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(17))) << "|" <<
		mult_string(" ",80) << "|" << 
		 firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(33))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(17))) << "|" <<
		mult_string(" ",80) << "|" << 
		 secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(33))) << "|" << std::endl; 
	in << "|" << thirdline_print(b.getSquare(17)) << "|" <<
		mult_string(" ",80) << "|" << 
		 thirdline_print(b.getSquare(33)) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(17)) << "|" <<
		mult_string(" ",80) << "|" << 
		 fourthline_print(b.getSquare(33)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << mult_string(" ",80) << "|" << mult_string("-",8) << "|" << std::endl;
	//16 34
	in << "|" << firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(16))) << "|" <<
		mult_string(" ",80) << "|" << 
		 firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(34))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(16))) << "|" <<
		mult_string(" ",80) << "|" << 
		 secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(34))) << "|" << std::endl; 
	in << "|" << thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(16))) << "|" <<
		mult_string(" ",80) << "|" << 
		 thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(34))) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(16)) << "|" <<
		mult_string(" ",17) << mult_string("-",46) << mult_string(" ",17) << "|" << 
		 fourthline_print(b.getSquare(34)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << 
		mult_string(" ",16) << "|" << mult_string(" ",46) << "|" << mult_string(" ",16) << "|"  <<
		mult_string("-",8) << "|" << std::endl;
	//15 35 
	in << "|" << firstline_print(std::dynamic_pointer_cast<Residence>(b.getSquare(15))) << "|" <<
		mult_string(" ",16) << "|" << 
		" #   #  ##  #####  ###   ###   ###  #   #   # " << 
		"|" << mult_string(" ",16) << "|"  <<
		 firstline_print(std::dynamic_pointer_cast<Residence>(b.getSquare(35))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<Residence>(b.getSquare(15))) << "|" <<
		mult_string(" ",16) << "|" << 
		" #   # #  #   #   #   #  #  # #   # #   #   # " << 
		"|" << mult_string(" ",16) << "|"  <<
		 secondline_print(std::dynamic_pointer_cast<Residence>(b.getSquare(35))) << "|" << std::endl; 
	in << "|" << thirdline_print(b.getSquare(15)) << "|" <<
		mult_string(" ",16) << "|" << 
		" # # # ####   #   #   #  ###  #   # #    # #  " << 
		"|" << mult_string(" ",16) << "|"  <<
		 thirdline_print(b.getSquare(35)) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(15)) << "|" <<
		mult_string(" ",16) << "|" << 
		" # # # #  #   #   #   #  #    #   # #     #   " << 
		"|" << mult_string(" ",16) << "|"  <<
		 fourthline_print(b.getSquare(35)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << 
		mult_string(" ",16) << "|" << 
		" ##### #  #   #    ###   #     ###  ## #  #   " << 
		"|" << mult_string(" ",16) << "|"  <<
		mult_string("-",8) << "|" << std::endl;
	// 14 36 
	in << "|" << firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(14))) << "|" <<
		mult_string(" ",16) << "|" << mult_string("-",46) << "|" << mult_string(" ",16) << "|" <<
		 firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(36))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(14))) << "|" <<
		mult_string(" ",80) << "|" << 
		 secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(36))) << "|" << std::endl; 
	in << "|" << thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(14))) << "|" <<
		mult_string(" ",80) << "|" << 
		 thirdline_print(b.getSquare(36)) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(14)) << "|" <<
		mult_string(" ",80) << "|" << 
		 fourthline_print(b.getSquare(36)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << mult_string(" ",80) << "|" << mult_string("-",8) << "|" << std::endl;
	//13 37
	in << "|" << firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(13))) << "|" <<
		mult_string(" ",80) << "|" << 
		 firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(37))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(13))) << "|" <<
		mult_string(" ",80) << "|" << 
		 secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(37))) << "|" << std::endl; 
	in << "|" << thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(13))) << "|" <<
		mult_string(" ",80) << "|" << 
		 thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(37))) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(13)) << "|" <<
		mult_string(" ",80) << "|" << 
		 fourthline_print(b.getSquare(37)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << mult_string(" ",80) << "|" << mult_string("-",8) << "|" << std::endl;
	//12 38
	in << "|" << firstline_print(std::dynamic_pointer_cast<Gym>(b.getSquare(12))) << "|" <<
		mult_string(" ",80) << "|" << 
		 firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(38))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<Gym>(b.getSquare(12))) << "|" <<
		mult_string(" ",80) << "|" << 
		 secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(38))) << "|" << std::endl; 
	in << "|" << thirdline_print(b.getSquare(12)) << "|" <<
		mult_string(" ",80) << "|" << 
		 thirdline_print(b.getSquare(38)) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(12)) << "|" <<
		mult_string(" ",80) << "|" << 
		 fourthline_print(b.getSquare(38)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << mult_string(" ",80) << "|" << mult_string("-",8) << "|" << std::endl;
	//11 39
	in << "|" << firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(11))) << "|" <<
		mult_string(" ",80) << "|" << 
		 firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(39))) << "|" << std::endl; 
	in << "|" << secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(11))) << "|" <<
		mult_string(" ",80) << "|" << 
		 secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(39))) << "|" << std::endl; 
	in << "|" << thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(11))) << "|" <<
		mult_string(" ",80) << "|" << 
		 thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(39))) << "|" << std::endl; 
	in << "|" << fourthline_print(b.getSquare(11)) << "|" <<
		mult_string(" ",80) << "|" << 
		 fourthline_print(b.getSquare(39)) << "|" << std::endl; 
	in << "|" << mult_string("-",8) << "|" << mult_string("-",80) << "|" << mult_string("-",8) << "|" << std::endl;
	//10 - 0
	in << "|" << firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(10))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(9))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(8))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(7))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(6))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Residence>(b.getSquare(5))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(4))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(3))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(2))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(1))) << "|" << 
		firstline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(0))) << "|" << std::endl;
	in << "|" << secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(10))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(9))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(8))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(7))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(6))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Residence>(b.getSquare(5))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(4))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(3))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(2))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(1))) << "|" << 
		secondline_print(std::dynamic_pointer_cast<NonProperty>(b.getSquare(0))) << "|" << std::endl;
	in << "|" << thirdline_print(b.getSquare(10)) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(9))) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(8))) << "|" << 
		thirdline_print(b.getSquare(7)) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(6))) << "|" << 
		thirdline_print(b.getSquare(5)) << "|" << 
		thirdline_print(b.getSquare(4)) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(3))) << "|" << 
		thirdline_print(b.getSquare(2)) << "|" << 
		thirdline_print(std::dynamic_pointer_cast<Upgradable>(b.getSquare(1))) << "|" << 
		thirdline_print(b.getSquare(0)) << "|" << std::endl;
	in << "|" << fourthline_print(b.getSquare(10)) << "|" << 
		fourthline_print(b.getSquare(9)) << "|" << 
		fourthline_print(b.getSquare(8)) << "|" << 
		fourthline_print(b.getSquare(7)) << "|" << 
		fourthline_print(b.getSquare(6)) << "|" << 
		fourthline_print(b.getSquare(5)) << "|" << 
		fourthline_print(b.getSquare(4)) << "|" << 
		fourthline_print(b.getSquare(3)) << "|" << 
		fourthline_print(b.getSquare(2)) << "|" << 
		fourthline_print(b.getSquare(1)) << "|" << 
		fourthline_print(b.getSquare(0)) << "|" << std::endl;
	in << "|" << mult_string("-",8) << "|" << mult_string("-",8) << "|" << mult_string("-",8) << 
		"|" << mult_string("-",8) << "|" << mult_string("-",8) << "|" << mult_string("-",8) << 
		"|" << mult_string("-",8) << "|" << mult_string("-",8) << "|" << mult_string("-",8) << 
		"|" << mult_string("-",8) << "|" << mult_string("-",8) << "|" << std::endl;
	return in;
}

std::string mult_string(std::string s, int n){
	if(n == 0){
		return "";
	}
	std::string tmp = "";
	while(n > 0){
		tmp += s;
		--n;
	}
	return tmp;
}

std::string firstline_print(std::shared_ptr<NonProperty> np){
	std::string name = np->getName();
	if(name == "Goose Nesting"){
		return "GOOSE   ";
	}else if(name == "NH"){
		return "NEEDLES ";
	}else if(name == "Go To Tims"){
		return "GO TO   ";
	}else if(name == "Co-op Fee"){
		return "CO-OP   ";
	}else if(name == "DC Tim's Line"){
		return "DC TIMS ";
	}else if(name == "Collect OSAP"){
		return "COLLECT ";
	}else{
		return "TUITION ";
	}
}// Name print

std::string firstline_print(std::shared_ptr<Upgradable> up){
	int num = up->getImprovements();
	std::string result_s = "";
	for(int n = 0; n < num; ++n){
		result_s += "I";
	}for(int n = 0; n < 8 - num; ++n){
		result_s += " ";
	}
	return result_s;
} //improvement print

std::string firstline_print(std::shared_ptr<Residence> res){
	std::string name = res->getName();
	if(name == "MKV"){
		return "MKV     ";
	}else if(name == "UWP"){
		return "UWP     ";
	}else if(name == "V1"){
		return "V1      ";
	}else{
		return "REV     ";
	}
} // Name print

std::string firstline_print(std::shared_ptr<Gym> gym){
	std::string name = gym->getName();
	if(name == "PAC"){
		return "PAC     ";
	}else{
		return "CIF     ";
	}
} // Name print

std::string secondline_print(std::shared_ptr<NonProperty> np){
		std::string name = np->getName();
	if(name == "Goose Nesting"){
		return "NESTING ";
	}else if(name == "NH"){
		return "HALL    ";
	}else if(name == "Go To Tims"){
		return "TIMS    ";
	}else if(name == "Co-op Fee"){
		return "FEE     ";
	}else if(name == "DC Tim's Line"){
		return "LINE    ";
	}else if(name == "Collect OSAP"){
		return "OSAP    ";
	}else{
		return "        ";
	}
}// Name print

std::string secondline_print(std::shared_ptr<Upgradable> up){
	return mult_string("-",8);
} //'-' print

std::string secondline_print(std::shared_ptr<Residence> res){
	return mult_string(" ",8);
} // space print
std::string secondline_print(std::shared_ptr<Gym> gym){
	return mult_string(" ",8);
} // space print

std::string thirdline_print(std::shared_ptr<Square>){
	return mult_string(" ",8);
} // space print
std::string thirdline_print(std::shared_ptr<Upgradable> up){
	std::string name = up->getName();
	return name + mult_string(" ",8-name.length());
} // name print


std::string fourthline_print(std::shared_ptr<Square> sq){
	std::vector<char> player_names = {'G','B', 'D','P','S','$','L','T'};
	std::vector<Player *> players = sq->getPlayers();
	std::string tmp = "";
	for(auto it=players.begin();it!=players.end();++it){
		char name = (*it)->getPiece();
		if(std::find(player_names.begin(),player_names.end(),name)!=player_names.end()){
			std::string str_name(1,name);
			tmp += str_name;
		}
	}
	return tmp + mult_string(" ",8 - players.size());
} // player print

#ifndef _GYM_
#define _GYM_

#include "property.h"
#include <random>

class Gym : public Property {
public:
	Gym(std::string name, std::shared_ptr<MonopolyBlock> b);
	int usageFees();
<<<<<<< HEAD
	void playerEffect(Player&);
	int getImprovements() override;
	void setImprovements(int improvement) override;
=======
	void playerEffect(std::shared_ptr<Player>);
	void mortgageBy(Player * player) override;
	void unmortgageBy(Player * player) override;
>>>>>>> 0e52b58418b97fca2b539f421348d294fe7ccf57
};

#endif


#ifndef ENTITY_H
#define ENTITY_H

#include "army.h"

class Commander {
public:
	bool is_player() const;
	void set_player(bool isPlayer);
	Army get_army();
	void set_army(Army army);
private:
	Army army_;
	bool isPlayer_;
};

#endif


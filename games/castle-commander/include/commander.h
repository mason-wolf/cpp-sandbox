#ifndef ENTITY_H
#define ENTITY_H

#include "army.h"

class Commander {
public:
	bool IsPlayer() const;
	void SetPlayer(bool isPlayer);

	Army& GetArmy();
	const Army& GetArmy() const;

	void SetArmy(Army& army);
private:
	Army* army_;
	bool isPlayer_;
};

#endif


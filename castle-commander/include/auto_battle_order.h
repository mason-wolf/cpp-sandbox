#ifndef AUTO_BATTLE_ORDER_H
#define AUTO_BATTLE_ORDER_H

#include "order.h"
#include "army.h"
#include <vector>

class AutoBattleOrder : public Order {
public:
	AutoBattleOrder(const Army&  opponentArmy);
	void Execute() override;

private:
	Army opponentArmy;
};

#endif

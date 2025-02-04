#ifndef AUTO_BATTLE_ORDER_H
#define AUTO_BATTLE_ORDER_H

#include "order.h"

class AutoBattleOrder : public Order {
public:
	AutoBattleOrder();
	void Execute() override;
};

#endif

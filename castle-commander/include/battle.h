#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <vector>
#include "unit.h"
#include "commander.h"

class Battle {
public:
	std::vector<Unit> fill_line(int size, int row, UnitType unitType);
	void populate_units(const std::vector<Unit>& units, int row, int col);
	void build_formation(bool isPlayer, std::vector<Unit> infantry, std::vector<Unit> archers, std::vector<Unit> cavalry);
	void set_player(const Commander& player);
	void set_opponent(const Commander& opponent);
	void start();
	Commander get_player() const;
	Commander get_opponent() const;
private:
	Commander player_;
	Commander opponent_;
};

#endif 

#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <vector>
#include "unit.h"
#include "commander.h"

class Battle {
public:
	/**
	Populates a row of units depending on unit type.
	Responsible for ASCII and unit placement.
	**/
	std::vector<Unit> fill_line(int size, int row, UnitType unitType);
	/**
	Assigns each unit its row and column.
	**/
	void populate_units(const std::vector<Unit>& units, int row, int col);
	/**
	Builds a unit group formation depending on unit type.
	By default, cavalry are in the back row, then archers, then infantry.
	**/
	void build_formation(bool isPlayer, std::vector<Unit> infantry, std::vector<Unit> archers, std::vector<Unit> cavalry);
	/**
	Calculates the largest unit group for formation sizing.
	Ensures the formations are properly formed in front of each other.
	**/
	UnitType calculate_largest_group(std::vector<Unit> infantry, std::vector<Unit> archers, std::vector<Unit> cavalry);
	// Assigns the player commander to the battle.
	void set_player(const Commander& player);
	// Assigns the opponent commander to the battle.
	void set_opponent(const Commander& opponent);
	// Starts the battle.
	void start();
	Commander get_player() const;
	Commander get_opponent() const;
  	void set_offset(int offset);
  	int convert_unit_type_to_row(UnitType unitType);
private:
	Commander player_;
	Commander opponent_;
};

#endif 

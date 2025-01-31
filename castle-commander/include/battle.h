#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <vector>
#include <array>
#include "unit.h"
#include "commander.h"

class Battle {
public:
	/**
	Populates a row of units depending on unit type.
	Responsible for ASCII and unit placement.
	**/
	std::vector<Unit> FillLine(int size, int row, UnitType unitType);
	/**
	Assigns each unit its row and column.
	**/
	void PopulateUnits(const std::vector<Unit>& units, int row, int col);
	/**
	Builds a unit group formation depending on unit type.
	By default, cavalry are in the back row, then archers, then infantry.
	**/
	void BuildFormation(bool isPlayer, std::vector<Unit> infantry, std::vector<Unit> archers, std::vector<Unit> cavalry);
	/**
	Calculates the largest unit group for formation sizing.
	Ensures the formations are properly formed in front of each other.
	**/
	std::array<int, 2> CalculateLargestGroup(std::vector<Unit> infantry, std::vector<Unit> archers, std::vector<Unit> cavalry);
	// Assigns the player commander to the battle.
	void SetPlayer(const Commander& player);
	// Assigns the opponent commander to the battle.
	void SetOpponent(const Commander& opponent);
	std::array<int, 2> GetPlayerForceOffset() const;
	std::array<int, 2> GetOpponentForceOffset() const;
	// Starts the battle.
	void Start();
	Commander GetPlayer() const;
	Commander GetOpponent() const;
  	void SetOffset(int offset);
  	int ConvertUnitTypeToRow(UnitType unitType);
private:
	Commander player_;
	Commander opponent_;
	std::array<int, 2> playerForceOffset_ = {0, 0};
	std::array<int, 2> opponentForceOffset_ = {0, 0};
};

#endif 

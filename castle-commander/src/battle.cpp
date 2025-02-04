
#include "battle.h"
#include <cstdlib>
#include <string>

const int MAX_UNITS_PER_ROW = 80;
int DEFAULT_ROW_OFFSET = 25;
int playerActiveRow = 0;

std::vector<Unit> Battle::FillLine(int size, int row, UnitType unitType) {
	std::vector<Unit> line;
	for (int i = 0; i < size; i++) {
		Unit unit(row, i, unitType);
		line.push_back(unit);
	}
	return line;
}

void Battle::HandleCommand() {
	std::string userInput;

	while(true) {
		std::cout << "1. Auto Battle" << std::endl; 
		std::cout << "2. Order Infantry Forward" << std::endl;
		std::cout << "3. Order Archers Forward" << std::endl;
		std::cout << "4. Order Cavalry Forward" << std::endl;
		std::cout << "5. Retreat" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, userInput);
		std::cout << userInput;
		std::cout << GetOpponent().GetArmy().GetInfantry().size();
		DEFAULT_ROW_OFFSET = 25;
		Start();
	}
}

void Battle::PopulateUnits(const std::vector<Unit>& units, int row, int col) {
	for (auto i = 0U; i < units.size(); i++) {
		if(units[i].GetRow() == row && units[i].GetCol() == col) {
			if (units[i].GetType() == INFANTRY) {
				if (units[i].IsHostile()) {
					std::cout << "\033[1;31m" << "o" << "\033[0m";
				}
				else {
				std::cout << "\033[1;32m" << "o" << "\033[0m";
				}
			}
			else if (units[i].GetType() == ARCHERS) {
				if (units[i].IsHostile()) {
					std::cout << "\033[1;31m" << "\u2193" << "\33[0m";
				}
				else {
					std::cout << "\033[1;32m" << "\u2193" << "\033[0m";
				}
			}
			else if (units[i].GetType() == CAVALRY) {
				if  (units[i].IsHostile()) {
					std::cout << "\033[1;31m" << "@" << "\33[0m";
				}
				else {
					std::cout << "\033[1;32m" << "@" << "\033[0m";
				}
			}
		}
	}
}

void Battle::SetOffset(int offset) {
	for (int i = 0; i < offset; i++) {
		std::cout << " ";
	}
}

int Battle::ConvertUnitTypeToRow(UnitType unitType) {
	switch(unitType) {
		case INFANTRY:
			return 2;
		case ARCHERS:
			return 1;
		case CAVALRY:
			return 0;
		default:
			return -1;
	}
}

void ClearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

std::array<int, 2> Battle::CalculateLargestGroup(std::vector<Unit> infantry, std::vector<Unit> archers, std::vector<Unit> cavalry) {
	UnitType largestGroup = INFANTRY;
	size_t unitCount = 0;
	size_t infantrySize = infantry.size();
	size_t archersSize = archers.size();
	size_t cavalrySize = cavalry.size();

	if (archersSize > infantrySize && archersSize > cavalrySize) {
		largestGroup = ARCHERS;
		unitCount = archersSize;
	} else if (cavalrySize > infantrySize && cavalrySize > archersSize) {
		largestGroup = CAVALRY;
		unitCount = cavalrySize;
	} else if (infantrySize >= archersSize && infantrySize >= cavalrySize) {
		largestGroup = INFANTRY;
		unitCount = infantrySize;
	}
	
	int unitRow = ConvertUnitTypeToRow(largestGroup);
	return { static_cast<int>(unitRow), static_cast<int>(unitCount) };
}

std::array<int, 2> Battle::GetOpponentForceOffset() const {
	return this->opponentForceOffset_;
}

std::array<int, 2> Battle::GetPlayerForceOffset() const {
	return this->playerForceOffset_;
}

void Battle::BuildFormation(bool isPlayer, 
				std::vector<Unit> infantry, 
				std::vector<Unit> archers, 
				std::vector<Unit> cavalry) {
          int row  = 0;
          int offset = DEFAULT_ROW_OFFSET;

	int opponentForceOffset = GetOpponentForceOffset()[1];
	int playerForceOffset = GetPlayerForceOffset()[1];
	
	if (isPlayer && (opponentForceOffset > playerForceOffset)) {
		DEFAULT_ROW_OFFSET  = DEFAULT_ROW_OFFSET + (opponentForceOffset / 4) -(playerForceOffset / 4);
	}
	else if (!isPlayer && (opponentForceOffset < playerForceOffset)) {
		DEFAULT_ROW_OFFSET = DEFAULT_ROW_OFFSET + (playerForceOffset / 4) - (opponentForceOffset / 4);
	}

        for (int i = 0; i < 3; i++) {
          if (row  == 0) {
		if (isPlayer) {
			int previousRowOffset = DEFAULT_ROW_OFFSET + ((cavalry.size() - archers.size()) / 2);
			offset = previousRowOffset + ((archers.size() - infantry.size()) / 2);
		}
                  SetOffset(offset);
          }
          else if (row  == 1) {
		if (isPlayer) {
			offset = DEFAULT_ROW_OFFSET + ((cavalry.size() - archers.size()) / 2);
		}
		else {
			offset = offset + ((cavalry.size() - archers.size()) / 2);
		}
                  SetOffset(offset);
          } 
          else if (row  == 2) {
		if (isPlayer) {
			offset = DEFAULT_ROW_OFFSET;
			SetOffset(offset);
		}
		else {
                 offset = offset + ((archers.size() - infantry.size()) / 2);
                 SetOffset(offset);
		}
          }
          for (int j = 0; j < MAX_UNITS_PER_ROW; j++) {
                  PopulateUnits(infantry, i, j);
                  PopulateUnits(archers, i, j);
                  PopulateUnits(cavalry, i, j);
          }
          row++;
         std::cout << std::endl;
      }
}

void Battle::Start() {
	ClearScreen();
	int numOppInfantry = GetOpponent().GetArmy().GetNumInfantry();
	std::vector<Unit> oppInfantry = FillLine(numOppInfantry, 2, INFANTRY);	
	int numOppArchers = GetOpponent().GetArmy().GetNumArchers();
	std::vector<Unit> oppArchers = FillLine(numOppArchers, 1, ARCHERS);
	int numOppCavalry = GetOpponent().GetArmy().GetNumCavalry();
	std::vector<Unit> oppCavalry = FillLine(numOppCavalry, 0, CAVALRY);

	for (auto &unit : oppInfantry) {
		unit.SetHostile(true);
	}

	for (auto &unit : oppArchers) {
		unit.SetHostile(true);
	}

	for (auto &unit : oppCavalry) {
		unit.SetHostile(true);
	}

	GetOpponent().GetArmy().SetInfantry(oppInfantry);

	int numPlayerInfantry = GetPlayer().GetArmy().GetNumInfantry();
	std::vector<Unit> playerInfantry = FillLine(numPlayerInfantry, 0, INFANTRY);
	int numPlayerArchers = GetPlayer().GetArmy().GetNumArchers();
	std::vector<Unit> playerArchers = FillLine(numPlayerArchers, 1, ARCHERS);
	int numPlayerCavalry = GetPlayer().GetArmy().GetNumCavalry();
	std::vector<Unit> playerCavalry = FillLine(numPlayerCavalry, 2, CAVALRY);
	
	for (auto &unit : playerInfantry) {
		unit.SetHostile(false);
	}

	for (auto &unit : playerArchers) {
		unit.SetHostile(false);
	}

	for (auto &unit : playerCavalry) {
		unit.SetHostile(false);
	}

	this->opponentForceOffset_ = CalculateLargestGroup(oppInfantry, oppArchers, oppCavalry);
	this->playerForceOffset_ = CalculateLargestGroup(playerInfantry, playerArchers, playerCavalry);
	BuildFormation(false, oppInfantry, oppArchers, oppCavalry);
	std::cout << std::endl << std::endl;
	BuildFormation(true, playerInfantry, playerArchers, playerCavalry);
	HandleCommand();
}

Commander Battle::GetPlayer() const {
	return player_;
}

void Battle::SetPlayer(const Commander& player) {
	player_ = player;
}

void  Battle::SetOpponent(const Commander& opponent) {
	opponent_ = opponent;
}

Commander Battle::GetOpponent() const {
	return opponent_;
}


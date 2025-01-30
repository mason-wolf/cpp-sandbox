
#include "battle.h"

const int MAX_UNITS_PER_ROW = 80;
const int DEFAULT_ROW_OFFSET = 25;

std::vector<Unit> Battle::fill_line(int size, int row, UnitType unitType) {
	std::vector<Unit> line;
	for (int i = 0; i < size; i++) {
		Unit unit(row, i, unitType);
		line.push_back(unit);
	}
	return line;
}

void Battle::populate_units(const std::vector<Unit>& units, int row, int col) {
	for (auto i = 0U; i < units.size(); i++) {
		if(units[i].get_row() == row && units[i].get_col() == col) {
			if (units[i].get_type() == INFANTRY) {
				std::cout << "o";
			}
			else if (units[i].get_type() == ARCHERS) {
				std::cout << "\u2193";
			}
			else if (units[i].get_type() == CALVARY) {
				std::cout << "@";
			}
		}
	}
}

void Battle::set_offset(int offset) {
	for (int i = 0; i < offset; i++) {
		std::cout << " ";
	}
}

int Battle::convert_unit_type_to_row(UnitType unitType) {
	switch(unitType) {
		case INFANTRY:
			return 2;
		case ARCHERS:
			return 1;
		case CALVARY:
			return 0;
		default:
			return -1;
	}
}

UnitType Battle::calculate_largest_group(std::vector<Unit> infantry, std::vector<Unit> archers, std::vector<Unit> cavalry) {
	UnitType largestGroup = INFANTRY;
	
	size_t infantrySize = infantry.size();
	size_t archersSize = archers.size();
	size_t cavalrySize = cavalry.size();

	if (archersSize > infantrySize && archersSize > cavalrySize) {
		largestGroup = ARCHERS;
	} else if (cavalrySize > infantrySize && cavalrySize > archersSize) {
		largestGroup = CALVARY;
	} else if (infantrySize >= archersSize && infantrySize >= cavalrySize) {
		largestGroup = INFANTRY;
	}
	
	return largestGroup;
}

void Battle::build_formation(bool isPlayer, 
				std::vector<Unit> infantry, 
				std::vector<Unit> archers, 
				std::vector<Unit> cavalry) {
          int row  = 0;
          int offset = DEFAULT_ROW_OFFSET;
          bool infantrySet = false;
          bool archersSet = false;
          bool calvarySet = false;
	
	// Create private class variable to store the largest formation.
	// We want to center the smallest formation between the larger force.
	// TODO: Simply logic into seperate methods.

        for (int i = 0; i < 3; i++) {
          if (row  == 0) {
		if (isPlayer) {
			int previousRowOffset = DEFAULT_ROW_OFFSET + ((cavalry.size() - archers.size()) / 2);
			offset = previousRowOffset + ((archers.size() - infantry.size()) / 2);
		}
                  set_offset(offset);
          }
          else if (row  == 1) {
		if (isPlayer) {
			offset = DEFAULT_ROW_OFFSET + ((cavalry.size() - archers.size()) / 2);
		}
		else {
			offset = offset + ((cavalry.size() - archers.size()) / 2);
		}
                  set_offset(offset);
          } 
          else if (row  == 2) {
		if (isPlayer) {
			offset = DEFAULT_ROW_OFFSET;
			set_offset(offset);
		}
		else {
                 offset = offset + ((archers.size() - infantry.size()) / 2);
                 set_offset(offset);
		}
          }
          for (int j = 0; j < MAX_UNITS_PER_ROW; j++) {
                  populate_units(infantry, i, j);
                  populate_units(archers, i, j);
                  populate_units(cavalry, i, j);
          }
          row++;
         std::cout << std::endl;
      }
}

void Battle::start() {
	int numOppInfantry = get_opponent().get_army().get_num_infantry();
	std::vector<Unit> oppInfantry = fill_line(numOppInfantry, 2, INFANTRY);	
	int numOppArchers = get_opponent().get_army().get_num_archers();
	std::vector<Unit> oppArchers = fill_line(numOppArchers, 1, ARCHERS);
	int numOppCavalry = get_opponent().get_army().get_num_cavalry();
	std::vector<Unit> oppCavalry = fill_line(numOppCavalry, 0, CALVARY);

	build_formation(false, oppInfantry, oppArchers, oppCavalry);

	int numPlayerInfantry = get_player().get_army().get_num_infantry();
	std::vector<Unit> playerInfantry = fill_line(numPlayerInfantry, 0, INFANTRY);
	int numPlayerArchers = get_player().get_army().get_num_archers();
	std::vector<Unit> playerArchers = fill_line(numPlayerArchers, 1, ARCHERS);
	int numPlayerCavalry = get_player().get_army().get_num_cavalry();
	std::vector<Unit> playerCavalry = fill_line(numPlayerCavalry, 2, CALVARY);
	
	std::cout << std::endl << std::endl;
	build_formation(true, playerInfantry, playerArchers, playerCavalry);
}

Commander Battle::get_player() const {
	return player_;
}

void Battle::set_player(const Commander& player) {
	player_ = player;
}

void  Battle::set_opponent(const Commander& opponent) {
	opponent_ = opponent;
}

Commander Battle::get_opponent() const {
	return opponent_;
}


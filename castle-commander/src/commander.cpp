#include "commander.h"

bool Commander::is_player() const {
	return isPlayer_;
}

void Commander::set_player(bool isPlayer) {
	isPlayer_ = isPlayer;
}

Army Commander::get_army() {
	return army_;
}

void Commander::set_army(Army army) {
	army_ = army;
}

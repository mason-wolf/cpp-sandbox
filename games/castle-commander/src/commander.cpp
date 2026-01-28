#include "commander.h"

bool Commander::IsPlayer() const {
	return isPlayer_;
}

void Commander::SetPlayer(bool isPlayer) {
	isPlayer_ = isPlayer;
}

Army& Commander::GetArmy() {
	return *army_;
}

const Army& Commander::GetArmy() const {
	return *army_;
}

void Commander::SetArmy(Army& army) {
	army_ = &army;
}

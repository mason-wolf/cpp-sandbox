#include "army.h"

void Army::SetNumInfantry(int num) {
	infantry_ = num;
}

void Army::SetNumCavalry(int num) {
	cavalry_ = num;
}

void Army::SetNumArchers(int num) {
	archers_ = num;
}

int Army::GetNumInfantry() const {
	return infantry_;
}

int Army::GetNumArchers() const {
	return archers_;
}

int Army::GetNumCavalry() const {
	return cavalry_;
}

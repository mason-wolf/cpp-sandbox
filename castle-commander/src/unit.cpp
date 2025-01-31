#include "unit.h"

Unit::Unit(int row, int col, UnitType type) : row_(row), col_(col), type_(type) {}

int Unit::GetRow() const {
	return row_;
}

int Unit::GetCol() const {
	return col_;
}

UnitType Unit::GetType() const {
	return type_;
}

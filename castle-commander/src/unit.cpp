#include "unit.h"

Unit::Unit(int row, int col, UnitType type) : row_(row), col_(col), type_(type) {}

int Unit::get_row() const {
	return row_;
}

int Unit::get_col() const {
	return col_;
}

UnitType Unit::get_type() const {
	return type_;
}

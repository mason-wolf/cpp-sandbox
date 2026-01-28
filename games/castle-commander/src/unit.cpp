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

void Unit::SetHostile(bool isHostile) {
	this->isHostile_ = isHostile;
}

bool Unit::IsHostile() const {
	return this->isHostile_;
}

double Unit::GetTrainingLevel() const {
	return this->trainingLevel_;
}

void Unit::SetTrainingLevel(double trainingLevel) {
	trainingLevel_ = trainingLevel;
}

double Unit::GetEquipmentLevel() const {
	return this->equipmentLevel_;
}

void Unit::SetEquipmentLevel(double equipmentLevel) {
	equipmentLevel_ = equipmentLevel;
}

double Unit::GetMoraleLevel() const {
	return this->moraleLevel_;
}

void Unit::SetMoraleLevel(double moraleLevel) {
	moraleLevel_ = moraleLevel;
}

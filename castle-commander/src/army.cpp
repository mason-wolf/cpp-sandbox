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

void Army::SetInfantry(const std::vector<Unit>& infantry) {
	this->infantryGroup_ = infantry;
}

const std::vector<Unit>& Army::GetInfantry() const {
	return infantryGroup_;
}

void Army::SetArchers(const std::vector<Unit>& archers) {
	this->archerGroup_ = archers;
}

const std::vector<Unit>& Army::GetArchers() const {
	return archerGroup_;
}

void Army::SetCavalry(const std::vector<Unit>& cavalry) {
	this->cavalryGroup_ = cavalry;
}

const std::vector<Unit>& Army::GetCavalry() const {
	return cavalryGroup_;
}

void Army::SetTrainingLevel(const double trainingLevel) {
	trainingLevel_ = trainingLevel;
}

double Army::GetTrainingLevel() const {
	return trainingLevel_;
}

void Army::SetEquipmentLevel(const double equipmentLevel) {
	equipmentLevel_ = equipmentLevel;
}

double Army::GetEquipmentLevel() const {
	return equipmentLevel_;
}

void Army::SetMoraleLevel(const double moraleLevel) {
	moraleLevel_ = moraleLevel;
}

double Army::GetMoraleLevel() const {
	return moraleLevel_;
}

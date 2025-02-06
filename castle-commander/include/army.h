#ifndef ARMY_H
#define ARMY_H
#include <vector>
#include "unit.h"

class Army {
public:
	void SetNumInfantry(int num);
	void SetNumCavalry(int num);
	void SetNumArchers(int num);

	int GetNumInfantry() const;
	int GetNumArchers() const;
	int GetNumCavalry() const;
	
	void SetInfantry(const std::vector<Unit>& infantry);
	void SetCavalry(const std::vector<Unit>& cavalry);
	void SetArchers(const std::vector<Unit>& archers);

	void SetTrainingLevel(const double trainingLevel);
	double GetTrainingLevel() const;

	void SetEquipmentLevel(const double equipmentLevel);
	double GetEquipmentLevel() const;

	void SetMoraleLevel(const double moraleLevel);
	double GetMoraleLevel() const;

	const std::vector<Unit>& GetInfantry() const;
	const std::vector<Unit>& GetCavalry() const;
	const std::vector<Unit>& GetArchers() const;
	
private:
	int infantry_;
	int archers_;
	int cavalry_;

	std::vector<Unit> infantryGroup_;
	std::vector<Unit> cavalryGroup_;
	std::vector<Unit> archerGroup_;

	double trainingLevel_;
	double equipmentLevel_;
	double moraleLevel_;
};

#endif

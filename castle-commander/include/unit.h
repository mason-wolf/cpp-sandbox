#ifndef UNIT_H
#define UNIT_H

enum UnitType { INFANTRY, ARCHERS, CAVALRY };

class Unit {
public:
	Unit(int row, int col, UnitType type);

	int GetRow() const;
	int GetCol() const;

	UnitType GetType() const;

	void SetHostile(bool isHostile);
	bool IsHostile() const;

	double GetTrainingLevel() const;
	void SetTrainingLevel(double trainingLevel);

	double GetEquipmentLevel() const;
	void SetEquipmentLevel(double equipmentLevel);

	double GetMoraleLevel() const;
	void SetMoraleLevel(double moraleLevel);

private:
	int row_;
	int col_;
	UnitType type_;
	bool isHostile_;

	double trainingLevel_;
	double equipmentLevel_;
	double moraleLevel_;
	
};

#endif

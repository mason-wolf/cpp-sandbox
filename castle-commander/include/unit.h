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
private:
	int row_;
	int col_;
	UnitType type_;
	bool isHostile_;
};

#endif

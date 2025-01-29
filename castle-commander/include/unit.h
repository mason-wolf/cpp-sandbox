#ifndef UNIT_H
#define UNIT_H

enum UnitType { INFANTRY, ARCHERS, CALVARY };

class Unit {
public:
	Unit(int row, int col, UnitType type);
	int get_row() const;
	int get_col() const;
	UnitType get_type() const;

private:
	int row_;
	int col_;
	UnitType type_;
};

#endif

#ifndef ARMY_H
#define ARMY_H

class Army {
public:
	void SetNumInfantry(int num);
	void SetNumCavalry(int num);
	void SetNumArchers(int num);

	int GetNumInfantry() const;
	int GetNumArchers() const;
	int GetNumCavalry() const;

	// TODO: Store units and change methods to refer
	// to this class rather than vectors.
private:
	int infantry_;
	int archers_;
	int cavalry_;
};

#endif

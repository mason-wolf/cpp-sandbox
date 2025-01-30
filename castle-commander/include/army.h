#ifndef ARMY_H
#define ARMY_H

class Army {
public:
	void set_num_infantry(int num);
	void set_num_cavalry(int num);
	void set_num_archers(int num);

	int get_num_infantry() const;
	int get_num_archers() const;
	int get_num_cavalry() const;

	// TODO: Store units and change methods to refer
	// to this class rather than vectors.
private:
	int infantry_;
	int archers_;
	int cavalry_;
};

#endif

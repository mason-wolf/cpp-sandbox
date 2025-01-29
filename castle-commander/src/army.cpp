#include "army.h"

void Army::set_num_infantry(int num) {
	infantry_ = num;
}

void Army::set_num_cavalry(int num) {
	cavalry_ = num;
}

void Army::set_num_archers(int num) {
	archers_ = num;
}

int Army::get_num_infantry() const {
	return infantry_;
}

int Army::get_num_archers() const {
	return archers_;
}

int Army::get_num_cavalry() const {
	return cavalry_;
}

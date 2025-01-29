#include <iostream>
#include <vector>


std::vector<int> fill_line(int num);

int main() {
	
	int numInfantry = 10;
	int numArchers = 9;
	int numCalvary = 25;

        std::vector<int> infantry = fill_line(numInfantry);

	for (int i = 0; i < 4; i++) {
		std::cout << i;
		for (int j = 0; j < 75; j++) {
			std::cout << j;
		}
		std::cout << "\n";
	}
}

std::vector<int> fill_line(int num) {
	std::vector<int> line;
	
	for (int i = 0; i < num; i++) {
		line.push_back(i);
	}
	return line;
}

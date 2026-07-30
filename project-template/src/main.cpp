#include <iostream>
#include <vector>
#include "csv_writer.h"


int main() {
	CSVWriter writer("output.csv");
	writer.write_row({"Name", "Age", "City"});
	std::cout << "Hello world!";
}

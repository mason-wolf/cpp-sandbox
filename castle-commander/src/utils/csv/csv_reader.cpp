#include "utils/csv/csv_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

CSVReader::CSVReader(const std::string& filename) : filename_(filename) {}

std::vector<std::vector<std::string>> CSVReader::read_all() {
	std::ifstream file(filename_);
	std::vector<std::vector<std::string>> data;
	std::string line;
	
	while(std::getline(file, line)) {
		std::vector<std::string> row;
		std::stringstream line_stream(line);
		std::string cell;

		while(std::getline(line_stream, cell, ',')) {
			row.push_back(cell);
		}
		
		data.push_back(row);
	}

	file.close();
	return data;
}

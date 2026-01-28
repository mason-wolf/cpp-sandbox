#include "utils/csv/csv_writer.h"
#include <fstream>

CSVWriter::CSVWriter(const std::string& filename) : filename_(filename) {}

void CSVWriter::write_row(const std::vector<std::string>& row) {
	std::ofstream file;
	file.open(filename_, std::ios::trunc);
	for (size_t i = 0; i < row.size(); ++i) {
		file << row[i];
		if (i < row.size() - 1) {
			file << ",";
		}
	}
	file << "\n";
	file.close();
}

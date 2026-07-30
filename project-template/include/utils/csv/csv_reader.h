#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>

class CSVReader {
public:
	CSVReader(const std::string& filename);
	std::vector<std::vector<std::string>> read_all();

private:
	std::string filename_;
};

#endif

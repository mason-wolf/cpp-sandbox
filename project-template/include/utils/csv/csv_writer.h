#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <string>
#include <vector>

class CSVWriter {
public:
	CSVWriter(const std::string& filename);
	void write_row(const std::vector<std::string>& row);

private:
	std::string filename_;
};

#endif

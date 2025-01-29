#include "utils/csv/mock_csv.h"
#include "utils/csv/mock_csv_data.h"
#include "utils/csv/csv_writer.h"
#include "utils/csv/csv_reader.h"
#include <vector>
#include <iostream>

void MockCSV::write_all() {
	CSVWriter writer("mock_csv.csv");
	std::vector<std::string> header = {"id", "name", "description"};
	std::vector<std::string> row1 {"1", "item1", "description1"};
	
	writer.write_row(header);
	writer.write_row(row1);
}

void MockCSV::read_all() {
	CSVReader reader("mock_csv.csv");
	std::vector<std::vector<std::string>> data = reader.read_all();
	
	std::vector<MockCSVData> mockCSVDataList;

	if(!data.empty()) {
		for (size_t i = 0; i <data.size(); ++i) {
			mockCSVDataList.emplace_back(data[i][0], data[i][1], data[i][2]);
		}
	}
	
	for (const auto& row : mockCSVDataList) {
		std::cout << row.id << ", " << row.name << ", " << row.description << std::endl;
	}
}


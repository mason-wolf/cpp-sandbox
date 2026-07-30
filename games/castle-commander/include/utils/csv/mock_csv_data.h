#ifndef CSV_DATA_H
#define CSV_DATA_H

#include <string>

class MockCSVData {
public:
	std::string id;
	std::string name;
	std::string description;
	
	MockCSVData(const std::string& id, const std::string& name, const std::string& description)
		: id(id), name(name), description(description) {}
};

#endif

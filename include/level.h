#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Level
{
private:
    int id;
    std::string prompt;
    std::map<std::string, std::string> options;

public:
    Level();
    ~Level();
    int getId();
    void setId(int id);
    std::string getPrompt();
    void setPrompt(std::string prompt);
    void addOption(std::string option, std::string destination);
    std::map<std::string, std::string> getOptions();
};

#endif
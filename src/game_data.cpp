#include "../include/game_data.h"
#include "../include/level.h"
#include "iostream"
#include "fstream"
#include "string"
#include <sstream>


std::vector<std::string> GameData::data;
/**
 * Handles comma-delimited file reading line by line.
 */
std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

/**
 * Loads the game data from file.
 */
void GameData::load() {
    std::ifstream file("game_data.txt");
    
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file.";
    }
}

/**
 * Loads the levels from the game data.
 */
void GameData::initLevels() {
    std::cout << "Loading levels..." << std::endl;
    for (size_t i = 0; i < data.size(); i++) {
        char delimiter = ',';
        std::vector<std::string> lines = splitString(data[i], delimiter);
        
        std::string dType = lines[0];
        
        if (dType == "LEVEL") {
            Level level;
            level.setId(std::stoi(lines[1]));
            level.setName(lines[2]);
            std::cout << "Level Id: " << level.getId() <<
                         " Name: " << level.getName() << std::endl;
        }
        // for (auto& str: lines) {
        //     std::cout << str << std::endl;
        // }
    }
}

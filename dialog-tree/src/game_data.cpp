#include "../include/game_data.h"
#include "../include/level.h"
#include "iostream"
#include "fstream"
#include "string"
#include <unordered_map>
#include <sstream>
#include <cstdlib>
#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "CLS"
#else
#define CLEAR "clear"
#endif

std::vector<std::string> GameData::data;
std::vector<Level> GameData::levels;
Level GameData::currentLevel;

/**
 * Handles comma-delimited file reading line by line.
 */
std::vector<std::string> splitString(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;

    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

void GameData::addLevel(Level level)
{
    levels.push_back(level);
}

std::vector<Level> GameData::getLevels()
{
    return levels;
}

/**
 * Loads the game data from file.
 */
void GameData::load()
{
    std::ifstream file("game_data.txt");

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            data.push_back(line);
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file.";
    }
}

/**
 * Load events from the game data.
 */
void GameData::init()
{
    for (size_t i = 0; i < data.size(); i++)
    {
        char delimiter = '|';
        std::vector<std::string> levelData = splitString(data[i], delimiter);
        std::vector<std::string> levelIdValue = splitString(levelData[0], '=');
        std::vector<std::string> options = splitString(levelData[1], ',');
        std::vector<std::string> promptData = splitString(levelData[2], '=');

        Level level;
        level.setId(std::stoi(levelIdValue[1]));
        level.setPrompt(promptData[1]);

        std::string currentOption;
        for (size_t j = 0; j < options.size(); j++)
        {
            if (options[j].find("option") != std::string::npos)
            {
                std::vector<std::string> optionData = splitString(options[j], '=');
                std::string optionValue = optionData[1];
                currentOption = optionValue;
            }

            if (options[j].find("destination") != std::string::npos)
            {
                std::vector<std::string> destData = splitString(options[j], '=');
                std::string destValue = destData[1];
                level.addOption(currentOption, destValue);
                currentOption.clear();
            }
        }

        levels.push_back(level);
    }
    loadLevel(1);
}

void GameData::loadLevel(int levelId)
{
    system(CLEAR);
    for (auto &l : levels)
    {
        if (l.getId() == levelId)
        {
            currentLevel = l;
            std::cout << l.getPrompt() << "\n"
                      << std::endl;
            int optionNum = 0;
            for (auto &option : l.getOptions())
            {
                optionNum++;
                std::cout << optionNum << " " << option.first << std::endl;
            }
        }
    }
}

#include "../include/level.h"
#include <map>

int id;
std::string prompt;
std::map<std::string, std::string> options;

Level::Level() {}

Level::~Level() {}

void Level::setId(int levelId)
{
    id = levelId;
}

int Level::getId()
{
    return id;
}

std::string Level::getPrompt()
{
    return prompt;
}

void Level::setPrompt(std::string levelPrompt)
{
    prompt = levelPrompt;
}

void Level::addOption(std::string optionName, std::string destinationId)
{
    options[optionName] = destinationId;
}

std::map<std::string, std::string> Level::getOptions()
{
    return options;
}

#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <iostream>
#include <vector>
#include <level.h>

class GameData
{
public:
    static std::vector<std::string> data;
    static std::vector<Level> levels;
    static Level currentLevel;

public:
    static void load();
    static void init();
    static void addLevel(Level level);
    static void loadLevel(int levelId);
    static std::vector<Level> getLevels();
};

#endif
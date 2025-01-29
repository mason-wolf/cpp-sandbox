#include "../include/game.h"
#include <iostream>

Game::Game() {}
Game::~Game() {}

void Game::start()
{
     GameData gameData;
     gameData.load();
     gameData.init();
     setGameData(gameData);
}

void Game::setGameData(GameData gameData)
{
     this->gameData = gameData;
}

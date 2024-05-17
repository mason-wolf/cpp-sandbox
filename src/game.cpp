#include "../include/game.h"
#include "../include/game_data.h"
#include <iostream>

Game::Game() {}
Game::~Game() {}

void Game::start() {
     GameData gameData;
     gameData.load();
     gameData.init();
}


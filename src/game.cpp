#include "../include/game.h"
#include "../include/game_data.h"
#include <iostream>

Game::Game() {}
Game::~Game() {}

void Game::start() {
     std::cout << GameData::events[0].getPrompt();
}


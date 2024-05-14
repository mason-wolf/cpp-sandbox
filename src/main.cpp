#include <iostream>
#include "game_data.h"
#include "game.h"
#include <string>
#include <csignal> 
#include <cstdlib> 

void exitHandler(int signal) {
    if (signal == SIGINT) {
        std::cout << "Goodbye! Safe travels brave warrior." << std::endl;
        exit(EXIT_SUCCESS);
    }
}

int main() {
    std::signal(SIGINT, exitHandler);
    GameData gameData;
    gameData.load();
    
    Game game;
    game.start();
    
    std::string option;
    
    while(true) {
        std::cin >> option;
    }
}